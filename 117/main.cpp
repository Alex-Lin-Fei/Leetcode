#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


Node* connect(Node* root) {
    queue<Node *> que;
    que.push(root);

    while (!que.empty()) {
        Node *pre = que.front();
        que.pop();
        int size = que.size();

        if (pre->left)
            que.push(pre->left);
        if (pre->right)
            que.push(pre->right);
        while (size--) {
            Node *temp = que.front();
            que.pop();
            pre->next = temp;
            pre = temp;
            if (temp->left)
                que.push(temp->left);
            if (temp->right)
                que.push(temp->right);
        }
        pre->next = nullptr;

    }

    return root;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
