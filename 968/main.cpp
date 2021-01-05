#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct State {
    int a; /*root必须被覆盖时，树被覆盖需要的监控数*/
    int b; /*整棵树被覆盖的监控数*/
    int c; /*两棵子树被覆盖的监控数*/

    State(int a_, int b_, int c_): a(a_), b(b_), c(c_) {}
};

State dfs(TreeNode* root) {
    if (root) {
        State left = dfs(root->left);
        State right = dfs(root->right);
        int a = left.c + right.c + 1;
        int b = min(a, min(right.a + left.b, right.b + left.a));
        int c = min(a, left.b + right.b);
        return State(a, b, c);
    } else
        return State(INT16_MAX, 0, 0);
}

int minCameraCover(TreeNode* root) {
    State state = dfs(root);
    return state.b;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
