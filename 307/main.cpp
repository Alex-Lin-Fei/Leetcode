#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int l, r;
    int sum;
    Node(int l, int r) : l(l), r(r) {}
};

class NumArray {
public:
    vector<Node> nodes;
    static int SUM;
    NumArray(vector<int>& nums) {
        nodes.resize(nums.size() * 2);
        buildTree(0, nums.size()-1, 0, nums);
    }

    void buildTree(int i, int j, int idx, vector<int>& nums) {
        nodes[idx] = Node(i,j);
        if (i == j)
            nodes[idx].sum = nums[i];
        else {
            buildTree(i, (i+j)>>1, (idx<<1)|1, nums);
            buildTree(((i+j)>>1)+1, j, (idx<<1)+2, nums);
            nodes[idx].sum = nodes[(idx<<1)|1].sum + nodes[(idx<<1)+2].sum;
        }
    }

    void update(int i, int val) {
        update(i, 0, val);
    }

    void update(int i, int idx, int val) {
        if (nodes[idx].l == nodes[idx].r)
            nodes[idx].sum += val;
        else {
            int mid = (nodes[idx].l + nodes[idx].r) >> 1;
            if (i <= mid)
                update(i, (idx << 1) | 1, val);
            else if (i > mid)
                update(i, (idx << 1) + 2, val);
            nodes[idx].sum = nodes[(idx << 1) | 1].sum + nodes[(idx << 1) + 2].sum;
        }
    }

    int sumRange(int i, int j) {
        SUM=0;
        sumRange(i, j, 0);
        return SUM;
    }

    void sumRange(int i, int j, int idx) {
        if (i <= nodes[idx].l && j >= nodes[idx].r) {
            SUM += nodes[idx].sum;
        }
        else if (i > nodes[idx].r || j < nodes[idx].l)
            ;
        else {
            int mid = (nodes[idx].l + nodes[idx].r) >> 1;
            if (j <= mid)
                sumRange(i, j, (idx << 1) | 1);
            else if (i > mid)
                sumRange(i, j, (idx << 1) + 2);
            else {
                sumRange(i, j, (idx << 1) | 1);
                sumRange(i, j, (idx <<1) + 2);
            }
        }
    }
};

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);

    NumArray numArray = NumArray(v);
    cout << numArray.sumRange(0,2)<<endl;

    return 0;
}
