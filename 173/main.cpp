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

class BSTIterator {
private:
    vector<int> nums;
    int cur;
    void inorder(TreeNode* root) {
        if (root) {
            inorder(root->left);
            nums.push_back(root->val);
            inorder(root->right);
        }
    }

public:
    BSTIterator(TreeNode* root) {
        inorder(root);
        cur = 0;
    }

    int next() {
        return nums[cur++];
    }

    bool hasNext() {
        return cur < nums.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
