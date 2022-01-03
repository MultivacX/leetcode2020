// 2095. Delete the Middle Node of a Linked List
// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

// Runtime: 1862 ms, faster than 5.06% of C++ online submissions for Delete the Middle Node of a Linked List.
// Memory Usage: 294.8 MB, less than 24.83% of C++ online submissions for Delete the Middle Node of a Linked List.

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
    ListNode *deleteMiddle(ListNode *head)
    {
        ListNode tmp(0, head);
        auto slow = &tmp;
        auto fast = slow;
        while (fast)
        {
            auto prev = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast)
            {
                fast = fast->next;
            }
            if (!fast)
            {
                prev->next = slow->next;
            }
        }
        return tmp.next;
    }
};