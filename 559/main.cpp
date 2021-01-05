#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

int step;
void bfs(Node * root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        while (size--) {
            Node * temp= q.front();
            q.pop();
            for (auto& node: temp->children){
                q.push(node);
            }
        }
        step++;
    }
}

int maxDepth(Node* root) {
    if(!root)
        return 0;
    bfs(root);
    return step;
//    if(!root) return 0;
//int maxL = 0;
//for (auto& node: root->children)
//    maxL = max(maxL, maxDepth(node));
//return maxL+1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
