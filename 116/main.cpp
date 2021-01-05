#include <iostream>
#include <queue>
#include <vector>
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
    if(!root)
        return nullptr;
    queue<Node*> que;
    Node* pre;

    que.push(root);

    while(!que.empty()) {
        int size = que.size();
//        temp.clear();
        while (size--) {
            Node *node = que.front();
            que.pop();
            if(pre== nullptr)
                pre=node;
            else{
                pre->next=node;
                pre=node;
            }
//            temp.push_back(node);
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
        pre->next= nullptr;
        pre= nullptr;
//        for (int i = 0; i < temp.size() - 1; i++)
//            temp[i]->next = temp[i + 1];
//        temp[temp.size() - 1]->next = nullptr;
    }
    return root;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
