#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
    if (l < r) {
        int mid = (l + r) >> 1;
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, l, mid);
        root->right = sortedArrayToBST(nums, mid+1,r);
        return root;
    }
    return nullptr;
}


TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size());
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
