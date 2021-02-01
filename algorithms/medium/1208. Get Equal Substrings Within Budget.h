// 1208. Get Equal Substrings Within Budget
// https://leetcode.com/problems/get-equal-substrings-within-budget/

// Runtime: 8 ms, faster than 91.11% of C++ online submissions for Get Equal Substrings Within Budget.
// Memory Usage: 7.8 MB, less than 12.34% of C++ online submissions for Get Equal Substrings Within Budget.

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        // i, len, cost(s[i - len + 1, i] to t[i - len + 1, i]) <= maxCost
        int ans = 0;
        for (int i = 0, len = 0, cost = 0; i < s.length(); ++i) {
            len += 1;
            cost += abs((int)s[i] - t[i]);
            int j = i - len + 1;
            while (cost > maxCost && j <= i) {
                len -= 1;
                cost -= abs((int)s[j] - t[j]);
                ++j;
            }
            if (j > i) len = 0, cost = 0;
            else ans = max(ans, len);
        }
        return ans;
    }
};