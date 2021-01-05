#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void swap(TreeNode * root){
    if (root) {
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        swap(root->left);
        swap(root->right);
    }
}

TreeNode* invertTree(TreeNode* root) {
    swap(root);
    return root;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
