// 1019. Next Greater Node In Linked List

// Runtime: 240 ms, faster than 46.52% of C++ online submissions for Next Greater Node In Linked List.
// Memory Usage: 24.3 MB, less than 88.24% of C++ online submissions for Next Greater Node In Linked List.

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
    vector<int> nextLargerNodes(ListNode* head) {
        if (!head) return {};
        
        stack<ListNode*> nodes;
        stack<int> idxs;
        vector<int> ans;
        auto p = head;
        while (p) {
            while (!nodes.empty() && nodes.top()->val < p->val) {
                nodes.pop();
                ans[idxs.top()] = p->val;
                idxs.pop();
            }
            nodes.push(p);
            idxs.push(ans.size());
            ans.push_back(0);
            p = p->next;
        }
        return ans;
    }
};