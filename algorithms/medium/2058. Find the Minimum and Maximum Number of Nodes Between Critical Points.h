// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

// Runtime: 349 ms, faster than 42.66% of C++ online submissions for Find the Minimum and Maximum Number of Nodes Between Critical Points.
// Memory Usage: 113.4 MB, less than 85.33% of C++ online submissions for Find the Minimum and Maximum Number of Nodes Between Critical Points.

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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        int dist_min = INT_MAX;
        int dist_max = INT_MIN;

        int cp_1st = 0;
        int cp_pre = 0;
        int i = 1;

        auto p = head;
        while (p)
        {
            auto q = p->next;
            if (!q)
                break;

            auto r = q->next;
            if (!r)
                break;

            if ((p->val < q->val && q->val > r->val) || (p->val > q->val && q->val < r->val))
            {
                if (cp_1st == 0)
                {
                    cp_1st = i;
                }
                else
                {
                    dist_max = max(dist_max, i - cp_1st);
                }

                if (cp_pre != 0)
                {
                    dist_min = min(dist_min, i - cp_pre);
                }
                cp_pre = i;
            }

            p = q;
            ++i;
        }

        if (dist_min == INT_MAX)
            dist_min = -1;
        if (dist_max == INT_MIN)
            dist_max = -1;
        return {dist_min, dist_max};
    }
};