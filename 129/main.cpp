#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int ans;

void getSum(TreeNode* root, int nowCount) {
    if (!root->left && !root->right)
        ans += nowCount * 10 + root->val;
    else {
        if (root->left)
            getSum(root->left, nowCount * 10 + root->val);
        if (root->right)
            getSum(root->right, nowCount * 10 + root->val);
    }
}

int sumNumbers(TreeNode* root) {
    ans = 0;
    getSum(root, 0);
    return ans;
}

int main() {


    return 0;
}
