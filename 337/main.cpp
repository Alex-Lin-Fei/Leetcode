#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

pair<int, int> dp(TreeNode* root) {
    if (!root)
        return make_pair(0, 0);
    pair<int, int>left = dp(root->left);
    pair<int, int>right = dp(root->right);
    int rob = root->val + left.first + right.first;
    int notRob = max(left.first, left.second) + max(right.first, right.second);
    return make_pair(notRob, rob);
}

int rob(TreeNode* root) {
    pair<int, int> r = dp(root);
    return max(r.first, r.second);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
