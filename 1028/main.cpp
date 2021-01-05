#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//int len = 1;

bool judge(string & str, int j, int i) {
    for (int k = j + 1; k < i; k++) {
        if (str[k] != '-')
            return false;
    }
    return true;
}

pair<int, int> findLen(string& str, int len) {
    pair<int, int> res = make_pair(-1, -1);
    for (int i = len + 1, j = 0; i < str.size(); i++, j++) {
        if (isdigit(str[i]) && isdigit(str[j]) && judge(str, j, i)) {
            if (res.first == -1)
                res.first = i;
            else {
                res.second = i;
                return res;
            }
        }
    }
    return res;
}

TreeNode* recoverFromPreorder(string S, int len) {
    int val = 0;
    int i = 0;
    while (i < S.size()) {
        if (isdigit(S[i])) {
            val *= 10;
            val += S[i] - '0';
            i++;
        }
        else {
            break;
        }
    }
    auto *root = new TreeNode(val);
    pair<int, int> res = findLen(S, len);
    if (res.first == -1 && res.second == -1)
        return root;
    string leftStr, rightStr;
    if (res.second != -1) {
        leftStr = S.substr(res.first, res.second  - len - res.first);
        rightStr = S.substr(res.second, S.size() - res.second);
    }
    else {
        leftStr = S.substr(res.first, S.size() - res.first);
        rightStr = "null";
    }
    cout << leftStr << ' ' << rightStr << endl;

    root->left = recoverFromPreorder(leftStr, len + 1);
    if (rightStr != "null")
        root->right = recoverFromPreorder(rightStr, len + 1);
    else
        root->right = nullptr;
    return root;
}

TreeNode* recoverFromPreorder(string S) {
    return recoverFromPreorder(S, 1);
}

void bfs(TreeNode* root) {
    queue<TreeNode* > q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        cout << node->val << ' ';
        q.pop();
        if (node->val != -1) {
            if (node->left || node->right) {
                if (node->left)
                    q.push(node->left);
                else
                    q.push(new TreeNode(-1));
                if (node->right)
                    q.push(node->right);
                else
                    q.push(new TreeNode(-1));
            }
        }
    }
}

int main() {
    string str = "1-401--349---90--88";
//    string sub = str.substr(0, 4);
//    std::cout << str << std::endl;
//    std::cout << sub << std::endl;
TreeNode* root = recoverFromPreorder(str, 1);
bfs(root);

    return 0;
}
