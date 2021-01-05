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


TreeNode* buildTree1(vector<int>& preorder, int prel,
                    int prer, vector<int>& inorder, int inl, int inr) {
    if (prel >= prer)
        return nullptr;
    int mid = find(inorder.begin()+inl, inorder.begin()+inr, preorder[prel++]) - inorder.begin();
    auto* root = new TreeNode(inorder[mid]);
    int l = mid-inl;

    root->left = buildTree1(preorder, prel, prel+l, inorder, inl, mid);
    root->right = buildTree1(preorder, prel+l, prer, inorder, mid+1, inr);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTree1(preorder, 0, preorder.size(), inorder, 0, inorder.size());
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
