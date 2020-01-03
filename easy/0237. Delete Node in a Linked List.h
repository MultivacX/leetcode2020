// 237. Delete Node in a Linked List

// Runtime: 12 ms, faster than 80.88% of C++ online submissions for Delete Node in a Linked List.
// Memory Usage: 9.2 MB, less than 88.46% of C++ online submissions for Delete Node in a Linked List.

// WTF

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        auto p = node->next;
        while (p) {
            node->val = p->val;
            if (p->next == nullptr) {
                node->next = nullptr;
                delete p;
                p = nullptr;
            } else {
                node = p;
                p = node->next;
            }
        }
    }
};