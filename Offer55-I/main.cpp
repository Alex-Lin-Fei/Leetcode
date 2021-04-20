#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
    if (!root)
        return 0;
    else
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
