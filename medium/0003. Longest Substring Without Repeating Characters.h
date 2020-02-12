// 3. Longest Substring Without Repeating Characters

// Runtime: 4 ms, faster than 99.37% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 9.2 MB, less than 93.03% of C++ online submissions for Longest Substring Without Repeating Characters.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int cnt[128] = {0};
        int ans = 1;
        cnt[s[0]] = 1;
        int begin = 0;
        for (int i = 1; i < s.length(); ++i) {
            char c = s[i];
            ++cnt[c];
            if (cnt[c] == 1) {
                ans = max(ans, i - begin + 1);
            } else {
                while (cnt[c] > 1) {
                    --cnt[s[begin++]];
                }
            }
        }
        return ans;
    }
};