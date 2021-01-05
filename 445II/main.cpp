#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2;
    int carry = 0;

//    装入数字
    ListNode *pre = l1;

    while (pre) {
        s1.push(pre->val);
        pre = pre->next;
    }

    pre = l2;
    while (pre) {
        s2.push(pre->val);
        pre = pre->next;
    }

    ListNode* cur = new ListNode(-1);

    while (!s1.empty() && !s2.empty()) {
        int a = s1.top();
        int b = s2.top();
        s1.pop();
        s2.pop();

        ListNode * now = new ListNode((a+b+carry)%10);
        carry = (a+b+carry)/10;
        now->next = cur->next;
        cur->next = now;
    }


    while (!s1.empty()) {
        int a = s1.top();
        s1.pop();
        ListNode * now = new ListNode((a+carry)%10);
        carry = (a+carry)/10;
        now->next = cur->next;
        cur->next = now;
    }

    while (!s2.empty()) {
        int a = s2.top();
        s2.pop();
        ListNode * now = new ListNode((a+carry)%10);
        carry = (a+carry)/10;
        now->next = cur->next;
        cur->next = now;
    }

    if (carry)
    {
        ListNode * now = new ListNode(carry%10);
        now->next = cur->next;
        cur->next = now;
    }

    return cur->next;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
