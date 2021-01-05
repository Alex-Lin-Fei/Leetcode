#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head) {
    ListNode* odd = new ListNode(-1);
    ListNode* even = new ListNode(-1);
    ListNode* pO = odd;
    ListNode* pE = even;
    ListNode* temp = head;

    while (temp && temp->next) {
        pO->next = temp;
        pE->next = temp->next;
        temp = temp->next->next;
        pO = pO->next;
        pE = pE->next;
    }
    if (temp) {
        pO->next = temp;
        pO = pO->next;
    }

    pO->next = even->next;
    return odd->next;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
