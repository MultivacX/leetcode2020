#ifndef _lclib_utils_h_
#define _lclib_utils_h_

#include "definition.h"

ListNode* createSinglyLinkedList(vector<int> v) {
    if (v.empty()) return nullptr;

    ListNode* head = new ListNode(v[0]);
    auto p = head;
    for (int i = 1; i < v.size(); ++i) {
        auto node = new ListNode(v[i]);
        p->next = node;
        p = node;
    }
    return head;
}

void printSinglyLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "null" << endl;
}

#endif // _lclib_utils_h_