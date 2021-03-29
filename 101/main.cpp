#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool compareLeftAndRight(TreeNode * left, TreeNode * right) {
    if (!left && !right)
        return true;
    else if (left && right) {
        return left->val == right->val && compareLeftAndRight(left->left, right->right) &&
               compareLeftAndRight(left->right, right->left);
    } else
        return false;
}

bool isSymmetric(TreeNode* root) {
    if (!root)
        return true;
    return compareLeftAndRight(root->left, root->right);
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
