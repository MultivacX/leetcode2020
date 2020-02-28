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

void print(vector<vector<int>>& v) {
    const int m = v.size();
    const int n = v[0].size();
    printf("    ");
    for (int j = 0; j < n; ++j) {
        printf("%2d ", j);
    }
    printf("\n");
    for (int i = 0; i < m; ++i) {
        printf("%2d: ", i);
        for (int j = 0; j < n; ++j) {
            printf("%2d,", v[i][j]);
        }
        printf("\n");
    }    
    printf("\n");
    printf("\n");
};

#endif // _lclib_utils_h_