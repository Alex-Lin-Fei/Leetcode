#include <iostream>
using namespace std;

struct TreeNode {
    int val;

    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int sum;

void dfs(TreeNode* root, int maximum) {
    if (!root)
        return;
    if (root->val >= maximum)
        sum++;
    maximum = max(maximum, root->val);
    dfs(root->left, maximum);
    dfs(root->right, maximum);
}

int goodNodes(TreeNode* root) {
    dfs(root, -1e5);
    return sum;
}

int main() {
    TreeNode * t1 = new TreeNode(3);
    TreeNode * t2 = new TreeNode(3);
    TreeNode * t3 = new TreeNode(4);
    TreeNode * t4 = new TreeNode(2);
    t1->left = t2;
    t2->left=t3;
    t2->right=t4;

    cout << goodNodes(t1);
    return 0;
}
