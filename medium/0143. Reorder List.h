// 143. Reorder List

// Runtime: 48 ms, faster than 79.77% of C++ online submissions for Reorder List.
// Memory Usage: 13.3 MB, less than 17.65% of C++ online submissions for Reorder List.

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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        vector<ListNode*> a;
        auto p = head;
        while (p) {
            a.push_back(p);
            p = p->next;
        }


        int l = 0;
        int r = a.size() - 1;
        ListNode* last = nullptr;
        while (l <= r) {
            auto p = a[l];
            auto q = a[r];
            if (last) last->next = p;
            p->next = q;
            last = q;
            ++l;
            --r;
        }
        if (last) last->next = nullptr;
    }
};