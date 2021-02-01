// 1446. Consecutive Characters
// https://leetcode.com/problems/consecutive-characters/

// Runtime: 4 ms, faster than 78.19% of C++ online submissions for Consecutive Characters.
// Memory Usage: 7 MB, less than 51.72% of C++ online submissions for Consecutive Characters.
    
class Solution {
public:
    int maxPower(string s) {
        int ans = 1;
        for (int i = 1, l = 1; i < s.length(); ++i) {
            if (s[i - 1] == s[i]) {
                ans = max(ans, ++l);
            } else {
                l = 1;
            }
        }
        return ans;
    }
};