#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;


    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int cur;

TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int left, int right) {
    if (left < right) {
        auto *root = new TreeNode(preorder[cur]);
        cur++;
        int i;
        for (i = left; i < right; i++) {
            if (root->val == inorder[i]) {
                break;
            }
        }

        root->left = dfs(preorder, inorder, left, i);
        root->right = dfs(preorder, inorder, i + 1, right);
        return root;
    }
    return nullptr;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return dfs(preorder, inorder, 0, preorder.size());
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
