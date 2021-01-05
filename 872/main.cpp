#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode * root, vector<int>& leaves) {
    if (!root)
        return;
    if (!root->right && !root->left)
        leaves.push_back(root->val);
    dfs(root->left, leaves);
    dfs(root->right, leaves);
}

void bfs(TreeNode * root, vector<int>& leaves) {
    if (!root)
        return;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()) {
        TreeNode *t = q.front();
        q.pop();
        if (!root->right && !root->left)
            leaves.push_back(root->val);
        if (root->left)
            q.push(root->left);
        if (root->right)
            q.push(root->right);
    }
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leaves1, leaves2;
    bfs(root1, leaves1);
    bfs(root2, leaves2);
    return leaves1 == leaves2;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
