#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* reverseBetween(ListNode* head, int left, int right) {
    auto* preH = new ListNode(-1);
    preH->next = head;

    auto pre = preH;
    int l = left - 1;

    while (l--)
        pre = pre->next;

    auto next = pre->next;
    auto temp = next->next;

    l = right - left + 1;
    pre->next = nullptr;
    while (l--) {
        next->next = pre->next;
        pre->next = next;
        next = temp;
        if (temp)
            temp = temp->next;
    }

    while (pre->next)
        pre = pre->next;
    pre->next = next;

    return preH->next;
}

int main() {
    auto head = new ListNode(1);
    auto pre = head;

    for (int i =2; i <= 5; i++) {
        pre->next = new ListNode(i);
        pre = pre->next;
    }
    head = reverseBetween(head, 1,1);

    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }


    return 0;
}
