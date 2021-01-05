#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> ans;
int currentVal, currentCount, maxCount;
void inorder(TreeNode * root) {
    if (root) {
        if (root->left)
            inorder(root->left);
        if (currentVal == root->val)
            currentCount++;
        else {
            currentVal = root->val;
            currentCount = 1;
        }

        if (currentCount == maxCount)
            ans.push_back(currentVal);
        else if (currentCount > maxCount) {
            maxCount = currentCount;
            ans.clear();
            ans.push_back(currentVal);
        }
        inorder(root->right);
    }
}
vector<int> findMode(TreeNode* root) {
    ans.clear();
    inorder(root);
    return ans;
}

int main() {
    return 0;
}
