// 382. Linked List Random Node

// Runtime: 48 ms, faster than 17.58% of C++ online submissions for Linked List Random Node.
// Memory Usage: 16.4 MB, less than 87.50% of C++ online submissions for Linked List Random Node.

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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) : list(head) {
        
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int ans = list->val;
        auto node = list;
        int n = 1;
        while (node->next) {
            node = node->next;
            ++n;
            if (rand() % n == 0) 
                ans = node->val;
        }
        return ans;
    }
    
    ListNode* list;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */