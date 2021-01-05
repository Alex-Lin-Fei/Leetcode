#include <iostream>
using namespace std;

struct ListNode {
    int val;

    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode *pre = head;
    ListNode *now = head;

    k--;
    while (k--)
        pre = pre->next;

    while (pre->next){
        pre = pre->next;
        now = now->next;
    }
    return now;
}

int main() {



    std::cout << "Hello, World!" << std::endl;
    return 0;
}
