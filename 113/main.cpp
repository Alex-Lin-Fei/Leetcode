#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<vector<int>> ans;
void dfs(TreeNode * root, vector<int> nowV, int count, int& sum) {
    if (!root)
        return;
    vector<int> newV = nowV;
    newV.push_back(root->val);
    if (!root->left && !root->right)
        if (count + root->val == sum)
            ans.push_back(newV);

        else {
            dfs(root->left, newV, count + root->val, sum);
            dfs(root->right, newV, count + root->val, sum);
        }
}


vector<vector<int>> pathSum(TreeNode* root, int sum) {
    ans.clear();
    dfs(root, vector<int>{}, 0, sum);
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
