#include <iostream>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeDuplicateNodes(ListNode* head) {
    set<int> s;
    ListNode* cur = head;
    auto* res = new ListNode(0);
    res->next = nullptr;
    while (cur) {
        if (!s.count(cur->val)) {
            s.insert(cur->val);
            ListNode* t = cur;
            cur = cur->next;
            t->next = res->next;
            res->next = t;
            res = t;
        }
        else
        cur = cur->next;
    }

    return res->next;
}


int main() {

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
