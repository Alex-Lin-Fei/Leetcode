#include <iostream>
//using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* left;
bool traverse(ListNode* right) {
    if (right == nullptr)
        return true;
    bool ans = traverse(right->next);
    ans = ans && (right->val == left->val);
    left = left->next;
    return ans;
}

bool isPalindrome(ListNode* head) {
    left = head;
    return traverse(head);
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
