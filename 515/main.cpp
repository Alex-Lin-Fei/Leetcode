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

vector<int> largestValues(TreeNode* root) {
    vector<int> ans;
    vector<TreeNode*>temp;
    queue<TreeNode*> q;
    long maxV;

    ans.push_back(root->val);
    q.push(root);
    while (true) {
        maxV = ;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                temp.push_back(node->left);
                maxV = max(maxV, node->left->val);
            }
            if (node->right) {
                temp.push_back(node->right);
                maxV = max(maxV, node->right->val);
            }
        }
        if (temp.empty())
            break;
        ans.push_back(maxV);
        for (auto& i: temp)
            q.push(i);
        temp.clear();
    }
    for (auto& i: ans)
        cout << i << ' ';
    return ans;
}

int main() {
    return 0;
}
