#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int minDiffInBST(TreeNode* root) {
    if (root) {
        int min_left = INT32_MAX;
        int min_right = INT32_MAX;

        if (root->left) {
            auto temp = root->left;
            while (temp->right) {
                temp = temp->right;
            }

            min_left = min(root->val - temp->val, minDiffInBST(root->left));
        }

        if (root->right) {
            auto temp = root->right;
            while (temp->left)
                temp= temp->left;

            min_right = min(temp->val - root->val, minDiffInBST(root->right));

        }

        return min(min_left, min_right);
    }

    return INT32_MAX;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
