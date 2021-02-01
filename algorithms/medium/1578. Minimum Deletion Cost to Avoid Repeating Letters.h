// 1578. Minimum Deletion Cost to Avoid Repeating Letters
// https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/

// Runtime: 316 ms, faster than 92.61% of C++ online submissions for Minimum Deletion Cost to Avoid Repeating Letters.
// Memory Usage: 95.7 MB, less than 7.32% of C++ online submissions for Minimum Deletion Cost to Avoid Repeating Letters.

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int ans = 0;
        char c = s[0];
        int cnt = 1;
        int curCost = cost[0];
        int maxCost = cost[0];
        for (int i = 1; i < s.length(); ++i) {
            if (c != s[i]) {
                if (cnt > 1) ans += curCost - maxCost;
                
                cnt = 0;
                curCost = 0;
                maxCost = 0;
            }
            
            c = s[i];
            ++cnt;
            curCost += cost[i];
            maxCost = max(maxCost, cost[i]);
        }
        if (cnt > 1) ans += curCost - maxCost;
        return ans;
    }
};

// Runtime: 740 ms, faster than 12.36% of C++ online submissions for Minimum Deletion Cost to Avoid Repeating Letters.
// Memory Usage: 100 MB, less than 7.32% of C++ online submissions for Minimum Deletion Cost to Avoid Repeating Letters.

class Solution {
    using min_heap = priority_queue<int, vector<int>, greater<int>>;
    
public:
    int minCost(string s, vector<int>& cost) {
        int ans = 0;
        min_heap h;
        h.push(cost[0]);
        char c = s[0];
        for (int i = 1; i < s.length(); ++i) {
            if (c != s[i]) {
                while (h.size() > 1) {
                    ans += h.top();
                    h.pop();
                }
                h.pop();
            }
            
            h.push(cost[i]);
            c = s[i];
        }
        while (h.size() > 1) {
            ans += h.top();
            h.pop();
        }
        return ans;
    }
};