#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;


    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next)
        return nullptr;
    ListNode * fast = head;
    ListNode * slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            break;
    }
    if (slow != fast)
        return nullptr;
    else {
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
