#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};




void sub_search(TreeNode* node, int dist) {
    if (!node)
        return;
    else if (dist == 0)
        ans.push_back(node->val);
    else
    {
        sub_search(node->left, dist-1);
        sub_search(node->right, dist-1);
    }
}

int dfs(TreeNode * node, TreeNode* target, int K) {
    if (!node)
        return -1;
    else if (node == target) {
        sub_search(node, K);
        return 0;
    }
    else {
        int l = dfs(node->left, target, K);
        int r = dfs(node->right, target, K);
        if (l != -1) {
            if (l == K-1)
                ans.push_back(node->val);
            sub_search(node->right, K - l - 2);
            return l + 1;
        } else if (r != -1) {
            if (r == K-1)
                ans.push_back(node->val);
            sub_search(node->left, K - r - 2);
            return r + 1;
        }
        else
            return -1;
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    dfs(root, target, K);
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
