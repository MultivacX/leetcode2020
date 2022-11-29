// 2487. Remove Nodes From Linked List
// https://leetcode.com/problems/remove-nodes-from-linked-list/

// Runtime: 439 ms, faster than 98.40% of C++ online submissions for Remove Nodes From Linked List.
// Memory Usage: 166.9 MB, less than 58.03% of C++ online submissions for Remove Nodes From Linked List.

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
class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {
        vector<ListNode *> stk;
        auto p = head;
        while (p)
        {
            while (!stk.empty() && stk.back()->val < p->val)
                stk.pop_back();
            stk.push_back(p);
            p = p->next;
        }
        for (int i = 0; i + 1 < stk.size(); ++i)
            stk[i]->next = stk[i + 1];
        if (!stk.empty())
        {
            stk.back()->next = nullptr;
            return stk[0];
        }
        return nullptr;
    }
};