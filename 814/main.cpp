#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool removeNull(TreeNode *root) {
    if (!root)
        return true;
    else {
        if (removeNull(root->left))
            root->left = nullptr;
        if (removeNull(root->right))
            root->right = nullptr;
        if (!root->left && !root->right && root->val == 0)
            return true;
        return false;
    }
}

TreeNode *pruneTree(TreeNode *root) {
    removeNull(root);

    return root;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
