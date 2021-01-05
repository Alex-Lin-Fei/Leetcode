#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int depth(TreeNode * cur) {
    return cur == nullptr? 0: max(depth(cur->left), depth(cur->right)) + 1;
}

bool isBalanced(TreeNode* root) {
    return root == nullptr ? true: (isBalanced(root->right) && isBalanced(root->left) && abs(depth(root->left) - depth(root->right)) <= 1);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
