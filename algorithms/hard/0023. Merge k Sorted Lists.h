// 23. Merge k Sorted Lists

// Runtime: 20 ms, faster than 98.95% of C++ online submissions for Merge k Sorted Lists.
// Memory Usage: 12.3 MB, less than 5.95% of C++ online submissions for Merge k Sorted Lists.

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return nullptr;
        while (n > 1) {
            int cnt = 0;
            for (int i = 0; i < n; i += 2) {
                //cout << i << endl;
                lists[i / 2] = merge(lists[i], i + 1 < n ? lists[i + 1] : nullptr);
                cnt += i + 1 < n ? 1 : 0;
            }
            n -= cnt;
        }
        return lists[0];
    }
    
    ListNode* merge(ListNode* a, ListNode* b) {
        if (!b) return a;
        ListNode ans(-1);
        auto p = &ans;
        while (a && b) {
            if (a->val <= b->val) {
                p->next = a;
                a = a->next;
            } else {
                p->next = b;
                b = b->next;
            }
            p = p->next;
        }
        if (p && (a || b)) p->next = a ? a : b;
        return ans.next;
    }
};


class Solution {
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        if (l1->val <= l2->val) {
            auto ll1 = l1->next;
            l1->next = mergeTwoLists(ll1, l2);
            return l1;
        } else {
            auto ll2 = l2->next;
            l2->next = mergeTwoLists(l1, ll2);
            return l2;
        }
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        while (lists.size() > 1) {
            vector<ListNode*> tmp;
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* p = lists[i];
                if (i + 1 < lists.size()) p = mergeTwoLists(lists[i], lists[i + 1]);
                if (p) tmp.push_back(p);
            }
            swap(lists, tmp);
        }
        if (lists.empty()) return nullptr;
        return lists.front();
    }
};