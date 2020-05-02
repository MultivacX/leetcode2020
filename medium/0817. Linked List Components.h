// 817. Linked List Components

// Runtime: 64 ms, faster than 33.43% of C++ online submissions for Linked List Components.
// Memory Usage: 21.6 MB, less than 5.26% of C++ online submissions for Linked List Components.

// Time Complexity: O(length(head)).
// Space Complexity: O(size(G)).

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
    int numComponents(ListNode* head, vector<int>& G) {
        if (!head) return 0;
        
        unordered_set<int> s(begin(G), end(G));
        int ans = 0;
        int cnt = 0;
        auto p = head;
        while (p) {
            if (s.count(p->val)) {
                ++cnt;
            } else {
                if (cnt != 0) ++ans;
                cnt = 0;
            }
            p = p->next;
        }
        if (cnt != 0) ++ans;
        return ans;
    }
};