#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA;
    ListNode *b = headB;

    while (a != b) {
        if (a->next)
            a = a->next;
        else
            a = headB;
        if (b->next)
            b = b->next;
        else
            b = headA;
    }
    return a;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
