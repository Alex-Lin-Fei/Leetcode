#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();

        vector<int> v;
        while (sz--) {
            TreeNode* temp = q.front();
            q.pop();

            v.push_back(temp->val);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        ans.push_back(v);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
