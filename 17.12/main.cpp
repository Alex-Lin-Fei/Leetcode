#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;

    TreeNode *left;

    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* ans, *cur;
void inorder(TreeNode* root) {
    if (!root)
        return;
    inorder(root->left);
    root->left = nullptr;
    cur->right = root;
    cur=root;
    inorder(root->right);
}

TreeNode* convertBiNode(TreeNode* root) {
    ans = new TreeNode(0);
    cur=ans;
    inorder(root);
    return ans->right;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
