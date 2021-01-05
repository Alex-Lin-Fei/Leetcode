#include <iostream>
using namespace std;

struct TreeNode {
    int val;

    TreeNode *left;

    TreeNode *right;


    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sum;
void change(TreeNode* root) {
    if (root) {
        change(root->right);
        sum += root->val;
        root->val = sum;
        change(root->left);
    }
}


TreeNode* bstToGst(TreeNode* root) {
    sum=0;
    change(root);
    return root;

}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
