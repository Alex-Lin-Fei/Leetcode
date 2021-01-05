#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int ans;
int getH(TreeNode* root) {
    if (!root)
        return 0;
    return max(getH(root->left), getH(root->right)) + 1;
}

void dfs(TreeNode* root, int H) {
    if (root->val % 2 == 0) {
        if (root->left) {
            if (root->left->left)
                ans += root->left->left->val;
            if (root->left->right)
                ans += root->left->right->val;
        }
        if (root->right) {
            if (root->right->right)
                ans += root->right->right->val;
            if (root->right->left)
                ans += root->right->left->val;
        }
    }
    if (H > 3) {
        dfs(root->left, H - 1);
        dfs(root->right, H-1);
    }
}

int sumEvenGrandparent(TreeNode* root) {
    int H = getH(root);
    if (H>3)
        dfs(root,H);
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
