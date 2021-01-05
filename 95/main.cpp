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

vector<TreeNode*> generateTrees(int start, int end) {
    vector<TreeNode*> res;
    if (end < start) {
        res.push_back(nullptr);
        return res;
    }
    for (int i = start; i <=end; i++) {
        for (auto& l: generateTrees(start, i-1)) {
            for (auto& r: generateTrees(i + 1, end)) {
                auto *root = new TreeNode(i);
                root->left = l;
                root->right = r;
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode*> generateTrees(int n) {
    return generateTrees(1, n);
}

int main() {
    vector<TreeNode*>res;
    for (int i = 0; i < 3; i++) {
        TreeNode* root = new TreeNode(-1);
        root->val = i;
        res.push_back(root);
    }
    for (auto& i: res)
        cout << i->val << ' ';

    return 0;
}
