// 725. Split Linked List in Parts

// Runtime: 12 ms, faster than 53.25% of C++ online submissions for Split Linked List in Parts.
// Memory Usage: 10 MB, less than 9.09% of C++ online submissions for Split Linked List in Parts.

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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int cnt = 0;
        auto node = root;
        while (node) {
            node = node->next;
            ++cnt;
        }
        
        vector<ListNode*> ans(k, nullptr);
        
        node = root;
            
        int size = cnt / k;
        int earlier_parts = cnt % k;
        int available_parts = min(k, cnt);
        
        for (int i = 0; i < available_parts; ++i) {
            int count = size + (i < earlier_parts ? 1 : 0);
            ans[i] = node;
            while (count > 1) {
                node = node->next;
                --count;
            }
            auto tmp = node;
            node = node->next;
            tmp->next = nullptr;
        }
        
        return ans;
    }
};