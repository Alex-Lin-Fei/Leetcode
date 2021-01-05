#include <iostream>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;

     explicit ListNode(int x) : val(x), next(nullptr) {}
 };

ListNode* insertionSortList(ListNode* head) {
    if (!head || !head->next)
        return head;
    ListNode *pre = head;
    ListNode *now = pre->next;
    while (now) {
        while (now && pre->val <= now->val) {
            pre = now;
            now = now->next;
        }
        if (!now)
            break;
        ListNode *tmp = now;
        pre->next = now->next;
        now = pre->next;
        if (tmp->val <= head->val) {
            ListNode *t = tmp;
            tmp->next = head;
            head = t;
        } else {
            ListNode *h = head;
            while (h != pre && tmp->val > h->next->val)
                h = h->next;
            tmp->next = h->next;
            h->next = tmp;
        }
    }
    pre = head;
    while (pre)
    {
        cout << pre->val<< ' ';
        pre=pre->next;
    }
    return head;
}


int main() {
    ListNode* head = new ListNode(-1);
    ListNode* pre = head;
    for(int i = 0; i < 4; i++) {
        int val;
        cin >> val;
        ListNode* tmp = new ListNode(val);
        pre->next = tmp;
        pre=tmp;
    }
    std::cout << "Hello, World!" << std::endl;
    insertionSortList(head);

    return 0;
}
