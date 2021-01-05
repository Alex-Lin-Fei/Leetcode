#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



int kthLargest(TreeNode *root, int k) {
    int ans = 0;
    stack<TreeNode *> stk;

    stk.push(root);

//    while (tmp->right) {
//        stk.push(tmp);
//        tmp = tmp->right;
//    }

    while (!stk.empty()) {
        if (stk.top()->right) {
            auto tmp =stk.top()->right;
            stk.top()->right = nullptr;
            stk.push(tmp);
        } else{
            if (k==1){
                ans = stk.top()->val;
                break;
            }
            else {
                auto tmp = stk.top()->left;
                stk.pop();
                if (tmp)
                    stk.push(tmp);
                k--;
            }
        }
    }
    return ans;
}

int main() {
    auto* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    cout << kthLargest(root, 6);

    return 0;
}
