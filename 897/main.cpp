#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* dfs(TreeNode* root)
{
    if (!root->left && !root->right)
        return root;
    TreeNode *left = nullptr;
    if (!root->left) {
        left = dfs(root->left);
        left->right = root;
    }
    else
        left  = root;
    left->left = nullptr;
    if (root->right)
        root->right = dfs(root->right);
    return left;
}

void inorder(TreeNode* root, vector<TreeNode*>& val) {
    if (!root)
        return;
    inorder(root->left, val);
    val.push_back(root);
    inorder(root->right, val);
}

TreeNode* increasingBST(TreeNode* root) {
//    return dfs(root);
vector<TreeNode*> val;
inorder(root, val);
TreeNode* ans = new TreeNode(0);
TreeNode* cur=ans;
for(auto&v: val)
{
    cur->right = v;
    cur=cur->right;
    cur->left = nullptr;
}
return ans->right;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
