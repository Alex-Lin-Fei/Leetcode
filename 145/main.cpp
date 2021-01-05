#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> ans;

void postorder(TreeNode * root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        ans.push_back(root->val);
    }
}
vector<int> postorderTraversal(TreeNode* root) {
    postorder(root);
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
