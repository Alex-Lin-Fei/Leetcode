#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return nullptr;
    } else {
//        找到left到right之间最大的元素
        int cur = max_element(nums.begin() + left, nums.begin() + right) - nums.begin();
        auto *root = new TreeNode(nums[cur]);
        root->left = buildTree(nums, left, cur);
        root->right = buildTree(nums, cur + 1, right);
        return root;
    }
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return buildTree(nums, 0, nums.size());
}

int main() {
    vector<int> nums{1,3,5,2,6};
    int cur = max_element(nums.begin() + 2, nums.begin() + 5) - nums.begin();

    std::cout << cur << std::endl;
    return 0;
}
