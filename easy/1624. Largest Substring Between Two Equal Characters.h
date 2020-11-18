// 1624. Largest Substring Between Two Equal Characters
// https://leetcode.com/problems/largest-substring-between-two-equal-characters/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Largest Substring Between Two Equal Characters.
// Memory Usage: 6.4 MB, less than 94.31% of C++ online submissions for Largest Substring Between Two Equal Characters.

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> v(26, -1);
        int ans = -1;
        for (int i = 0; i < s.length(); ++i) {
            int j = s[i] - 'a';
            if (v[j] < 0) v[j] = i;
            ans = max(ans, i - v[j] - 1);
        }
        return ans;
    }
};