#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int ans;

void dfs(TreeNode* root,int sum) {
    int now = 0;
    if (!root)
        return;
    now += root->val;
    if (now == sum)
        ans++;
    dfs(root->left, sum - now);
    dfs(root->right, sum - now);
}

int pathSum(TreeNode* root, int sum) {
    if (!root)
        return 0;
    dfs(root, sum);
    pathSum(root->left, sum);
    pathSum(root->right, sum);
    return ans;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
