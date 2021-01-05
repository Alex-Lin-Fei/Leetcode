#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    queue<TreeNode*>que;
    vector<vector<int>> ans;
    que.push(root);
    bool odd = true;

    while (!que.empty()) {
        int sz = que.size();
        vector<int> vals;
        while (sz--) {
            TreeNode* tmp = que.front();
            que.pop();
            vals.push_back(tmp->val);
            if (tmp->left)
                que.push(tmp->left);
            if (tmp->right)
                que.push(tmp->right);
        }
        if(!odd)
            reverse(vals.begin(), vals.end());
        ans.push_back(vals);
        odd = !odd;
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
