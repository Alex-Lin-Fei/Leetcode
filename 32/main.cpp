#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root)
        return {};
    queue<TreeNode* > nodeSet;
    vector<vector<int>> ans;
    vector<int> levelNumber;
    nodeSet.push(root);
    TreeNode* temp = nullptr;
    bool isEven = false;

    while(!nodeSet.empty()) {
        for (int i = nodeSet.size(); i > 0; i--) {
            temp = nodeSet.front();
            nodeSet.pop();
            levelNumber.push_back(temp->val);

            if (temp->left) nodeSet.push(temp->left);
            if (temp->right) nodeSet.push(temp->right);
        }
        if (isEven)
            reverse(levelNumber.begin(), levelNumber.end());
        isEven = !isEven;
        ans.push_back(levelNumber);
        levelNumber.clear();
    }
    return ans;
}

int main() {
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    reverse(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
        cout << a[i];
    return 0;
}
