// 1171. Remove Zero Sum Consecutive Nodes from Linked List

// Runtime: 20 ms, faster than 40.75% of C++ online submissions for Remove Zero Sum Consecutive Nodes from Linked List.
// Memory Usage: 12.3 MB, less than 100.00% of C++ online submissions for Remove Zero Sum Consecutive Nodes from Linked List.

// Time Complexity: O(length(head)).
// Space Complexity: O(length(head)).

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (!head) return head;
        if (!head->next) return head->val != 0 ? head : nullptr;
        
        ListNode X(1001, head);
        unordered_map<int, ListNode*> prefix{{0, &X}};
        unordered_map<ListNode*, int> m{{&X, 0}};
        
        auto pre = &X;
        auto p = head;
        int sum = 0;
        while (p) {
            auto next = p->next;
            
            if (p->val == 0) {
                // delete p
                pre->next = next;
            } else {
                sum += p->val;
                if (prefix.count(sum)) {
                    auto q = prefix[sum]->next;
                    prefix[sum]->next = next;
                    pre = prefix[sum];
                    // delete [prefix[sum]->next, p]
                    while (q != p) {
                        prefix.erase(m[q]);
                        m.erase(q);
                        q = q->next;
                    }
                } else {
                    prefix.emplace(sum, p);
                    m.emplace(p, sum);
                    pre = p;
                }
            }
            
            p = next;
        }
        return X.next;
    }
};