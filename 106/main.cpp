#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//int idx;
//TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int l, int r) {
//    if (l == r)
//        return nullptr;
//    int mid = find(inorder.begin() + l, inorder.begin() + r, postorder[idx]) - inorder.begin();
//
//
//    TreeNode *root = new TreeNode(postorder[idx--]);
//    root->right = dfs(inorder, postorder, l, mid);
//    root->left = dfs(inorder, postorder, mid + 1, r);
//    return root;
//}
//
//
//TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//    idx = postorder.size()-1;
//    return dfs(inorder, postorder, 0, postorder.size());
//}

int idx;

TreeNode* dfs(vector<int> & inorder, vector<int> & postorder, int l, int r) {
    if (l == r)
        return nullptr;
    int mid = find(inorder.begin()+l, inorder.begin()+r, postorder[idx]) - inorder.begin();
    TreeNode * root = new TreeNode(postorder[idx--]);
    root->right = dfs(inorder, postorder, mid+1, r);
    root->left = dfs(inorder, postorder, l, mid);
    return root;
}

TreeNode * buildTree(vector<int>& inorder, vector<int>& postorder){
    idx = inorder.size()-1;
    return dfs(inorder, postorder, 0, inorder.size());
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
