#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;

    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getHeight(TreeNode * root) {
    if (!root)
        return -1;
    return max(getHeight(root->left), getHeight(root->right)) + 1；
}

bool isBalanced(TreeNode* root) {
    if (!root)
        return true;
//    if (!root->right && !root->left)
//        return true;
    return abs(getHeight(root->left) - getHeight(root->right)) <= 1
           && isBalanced(root->left) && isBalanced(root->right);
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
