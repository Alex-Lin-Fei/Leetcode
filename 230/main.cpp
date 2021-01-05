#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int count;
int ans;
void inorder(TreeNode* root, int k) {
    if (!root)
        return;
    inorder(root->left, k);
    count++;
    if (count == k)
        ans = root->val;
    else
        inorder(root->right, k);
}

int kthSmallest(TreeNode* root, int k) {
    inorder(root, k);
    return ans;
}

int main() {

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
