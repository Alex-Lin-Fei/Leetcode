#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sum;
void getSum(TreeNode * root) {
    if (root){
        getSum(root->left);
        sum += root->val;
        getSum(root->right);
    }
}

void inorder(TreeNode* root, int& count) {
    if (root) {
        inorder(root->left, count);
        int temp = root->val;
        root->val = count;
        count -= temp;
        inorder(root->right, count);
    }
}

TreeNode* convertBST(TreeNode* root) {
    getSum(root);
    inorder(root, sum);
}

int main() {

    return 0;
}
