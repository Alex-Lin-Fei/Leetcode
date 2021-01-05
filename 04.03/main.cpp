#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};


vector<ListNode*> listOfDepth(TreeNode* tree) {
    queue<TreeNode*> q;
    vector<ListNode*> res;
    q.push(tree);


    while (!q.empty()) {
        int sz = q.size();
        auto* head = new ListNode(0);
        ListNode* h = head;
        while (sz--) {
            TreeNode* temp = q.front();
            q.pop();

            h->next = new ListNode(temp->val);
            h = h->next;

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        res.push_back(head->next);
    }
    return res;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
