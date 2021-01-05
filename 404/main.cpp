#include <iostream>
using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int ans;

void getSum(TreeNode * root, int dir) {
    if (!root)
        return;
    else if (dir == 0 && !root->left && !root->right)
        ans += root->val;
    else {
        if (root->left)
            getSum(root->left, 0);
        if (root->right)
            getSum(root->right, 1);
    }
}

int sumOfLeftLeaves(TreeNode* root) {
    ans = 0;
    if (root) {
        getSum(root->left, 0);
        getSum(root->right, 1);
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
