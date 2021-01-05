#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void process(TreeNode * node, unordered_set<int>& set, vector<TreeNode*> res) {
    if (!node)
        return;
    process(node->left, set, res);
    process(node->right, set, res);

    if (set.find(node->val)!= set.end()) {
        if (node->left)
            res.push_back(node->left);
        if (node->right)
            res.push_back(node->right);
        node= nullptr;
    }
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> res;

    unordered_set<int> set(to_delete.begin(), to_delete.end());

    process(root, set, res);

    if(root)
    {
        res.push_back(root);
    }

    return res;
}

int main() {


    return 0;
}
