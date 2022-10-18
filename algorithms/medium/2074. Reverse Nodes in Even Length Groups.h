// 2074. Reverse Nodes in Even Length Groups
// https://leetcode.com/problems/reverse-nodes-in-even-length-groups/

// Runtime: 2512 ms, faster than 10.74% of C++ online submissions for Reverse Nodes in Even Length Groups.
// Memory Usage: 364.5 MB, less than 11.04% of C++ online submissions for Reverse Nodes in Even Length Groups.

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
    ListNode *reverseEvenLengthGroups(ListNode *head)
    {
        vector<ListNode *> nodes;
        auto p = head;
        while (p)
        {
            nodes.push_back(p);
            p = p->next;
        }

        int i = 1, l = 2, n = nodes.size();
        while (true)
        {
            if (i + l > n)
            {
                if (n > i && (n - i) % 2 == 0)
                {
                    reverse(nodes.begin() + i, nodes.end());
                }
                break;
            }
            reverse(nodes.begin() + i, nodes.begin() + i + l);
            // for (int k = 0; k < n; ++k) cout << nodes[k]->val << ' '; cout << endl;

            i += l;
            ++l;
            if (i + l > n)
            {
                if (n > i && (n - i) % 2 == 0)
                {
                    reverse(nodes.begin() + i, nodes.end());
                }
                break;
            }

            i += l;
            ++l;
        }

        for (i = 0; i < n; ++i)
            nodes[i]->next = i + 1 < n ? nodes[i + 1] : nullptr;

        return head;
    }
};