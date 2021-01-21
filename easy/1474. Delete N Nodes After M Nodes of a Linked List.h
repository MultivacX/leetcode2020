// 1474. Delete N Nodes After M Nodes of a Linked List
// https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/

// Runtime: 32 ms, faster than 93.79% of C++ online submissions for Delete N Nodes After M Nodes of a Linked List.
// Memory Usage: 15.8 MB, less than 93.79% of C++ online submissions for Delete N Nodes After M Nodes of a Linked List.
    
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        if (!head) return head;
        auto p = head;
        int i = m - 1;
        while (p) {
            if (i > 0) {
                --i;
                p = p->next;
            } else {
                i = m - 1;
                auto q = p->next;
                
                int j = n;
                while (q) {
                    if (j > 0) {
                        --j;
                        q = q->next;
                    } else {
                        break;
                    }
                }
                p->next = q;
                p = p->next;
            }
        }
        return head;
    }
};