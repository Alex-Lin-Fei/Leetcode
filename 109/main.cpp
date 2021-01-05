#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode * sortedVector(vector<int>& nums, int l, int r) {
    if (l < r) {
        int mid = (l+r)>>1;
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = sortedVector(nums, l, mid);
        root->right = sortedVector(nums, mid+1, r);
        return root;

    }
    return nullptr;
}

TreeNode* sortedListToBST(ListNode* head) {
    vector<int> v;
    ListNode * p = head;
    while (p) {
        v.push_back(p->val);
        p = p->next;
    }
    return sortedVector(v, 0, v.size());
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
