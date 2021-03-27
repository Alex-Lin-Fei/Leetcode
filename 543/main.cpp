#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int getHeight(TreeNode* root) {
    if (!root) return 0;
    else return max(getHeight(root->left), getHeight(root->right)) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int len = 0;
    int left_len = 0;
    int right_len = 0;
    if (root->left) {
        len += getHeight(root->left);
        left_len = diameterOfBinaryTree(root->left);
    }
    if (root->right) {
        len += getHeight(root->right);
        right_len = diameterOfBinaryTree(root->right);
    }

    return max(len, max(right_len, left_len));
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
