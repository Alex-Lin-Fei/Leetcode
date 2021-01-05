#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode* x) {
    if (!x)
        return 0;
    return max(height(x->right), height(x->left))+1;
}

bool isBalanced(TreeNode* root) {
    if (!root)
        return true;
    return isBalanced(root->right) && isBalanced(root->left) &&
    abs(height(root->left) - height(root->right)) <= 1;
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
