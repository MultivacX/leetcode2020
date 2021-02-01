// 1669. Merge In Between Linked Lists
// https://leetcode.com/problems/merge-in-between-linked-lists/

// Runtime: 444 ms, faster than 16.67% of C++ online submissions for Merge In Between Linked Lists.
// Memory Usage: 95 MB, less than 66.67% of C++ online submissions for Merge In Between Linked Lists.
    
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto tmp = ListNode(0, list1);
        
        auto l = &tmp;
        while (a-- > 0) l = l->next;
        auto r = list1;
        while (b-- > 0) r = r->next;
        
        l->next = list2;
        auto p = list2;
        while (p->next) p = p->next;
        p->next = r->next;
        
        return tmp.next;
    }
};