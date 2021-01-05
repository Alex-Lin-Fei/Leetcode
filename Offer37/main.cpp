#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;

    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
