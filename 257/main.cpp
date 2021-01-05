#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> strroot;
    if (!root->left && !root->right)
        strroot.push_back(to_string(root->val));
    else {
        vector<string> l, r;
        if (root->left)
            l = binaryTreePaths(root->left);
        if (root->right)
            r = binaryTreePaths(root->right);
        for (auto& s: l)
            strroot.push_back(to_string(root->val) + "->" + s);
        for (auto& s: r)
            strroot.push_back(to_string(root->val) + "->" + s);
    }
    return strroot;
}

int main() {
    vector<string>v={"hhh","eee"};
    vector<string>v2 = v;
    for (auto& i: v)
        cout<<i<<' ';
    cout<<endl;
    v[0]="aaa";
    for (auto& i: v)
        cout<<i<<' ';
    cout<<endl;
    return 0;
}
