#include <iostream>
using namespace std;

struct ListNode {
    int val;

    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//合并链表
ListNode* mergeList(ListNode* pa, ListNode* pb) {
    ListNode *pre = new ListNode(-1);
    ListNode *tmp = pre;
    while (pa && pb) {
        if (pa->val <= pb->val) {
            pre->next = pa;
            pa = pa->next;
        } else {
            pre->next = pb;
            pb = pb->next;
        }
        pre = pre->next;
    }
    if (pa)
        pre->next = pa;
    else
        pre->next = pb;

    return tmp->next;
}

//  链表排序
ListNode* sortList(ListNode* head) {
    if (!head || !head->next)
        return head;
//    快慢指针
    ListNode *fast = head, *slow = head;

    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    fast = slow->next;
    slow->next = nullptr;
    slow = sortList(head);
    fast = sortList(fast);
    return mergeList(slow, fast);
}

int main() {
    int i = 5;
    ListNode* pre = new ListNode(-1);
    auto tmp = pre;
    while (i--) {
        int val;
        cin >> val;
        pre->next = new ListNode(val);
        pre=pre->next;
    }
    pre = sortList(tmp->next);
    while (pre) {
        cout << pre->val << ' ';
        pre = pre->next;
    }
    return 0;
}
