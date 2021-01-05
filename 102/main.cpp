#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>>ans;
    vector<int>temp;
    while (!q.empty()) {
        int len = q.size();
        while (len--) {
            TreeNode* node = q.front();
            q.pop();
            temp.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        ans.push_back(temp);
        temp.clear();
    }
    return ans;
}

int main() {

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
