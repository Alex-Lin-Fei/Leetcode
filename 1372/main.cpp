#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxR, maxL;
pair<int, int> dp(TreeNode* root) {
    if (!root->right && !root->left)
        return make_pair(0, 0);
    else {
        pair<int, int>dl = dp(root->left);
        pair<int, int>dr = dp(root->right);
        pair<int, int>d;

        d.first = 1 + dl.second;
        d.second = 1 + dr.first;
        maxR = max(maxR, max(d.second, dr.second));
        maxL = max(maxL, max(d.first, dl.first));
        return d;
    }
}

int ans;
void dfs(TreeNode* root, bool dir, int dis) {
    if (!root)
        return;
    ans = max(ans, dis);
    if (dir) {
        dfs(root->left, false, dis + 1);
        dfs(root->right, true, 1);
    }
    else {
        dfs(root->left, false, 1);
        dfs(root->right, true, dis + 1);
    }
}


int longestZigZag(TreeNode* root) {
//    if (!root)
//        return 0;
//    dp(root);
//    return max(maxL, maxR);
    dfs(root->left, false, 1);
    dfs(root->right, true, 1);
    return ans;
}


int main() {
    TreeNode* node = new TreeNode(1);
    std::cout << longestZigZag(node) << std::endl;
    return 0;
}
