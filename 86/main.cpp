#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *partition(ListNode *head, int x) {
    auto *less = new ListNode(-1);
    auto *more = new ListNode(-1);
    auto p1 = less;
    auto p2 = more;

    while (head) {
        if (head->val >= x) {
            p2->next = head;
            p2 = p2->next;
        } else {
            p1->next = head;
            p1 = p1->next;
        }
        auto tmp = head->next;
        head->next = nullptr;
        head = tmp;
    }
    p1->next = more->next;
    return less->next;
}

int main() {

    return 0;
}
