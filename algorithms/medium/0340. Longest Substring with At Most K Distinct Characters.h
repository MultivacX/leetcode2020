// 340. Longest Substring with At Most K Distinct Characters
// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

// Runtime: 24 ms, faster than 72.60% of C++ online submissions for Longest Substring with At Most K Distinct Characters.
// Memory Usage: 8.5 MB, less than 31.30% of C++ online submissions for Longest Substring with At Most K Distinct Characters.
    
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ans = 0;
        unordered_map<char, int> m;
        for (int i = 0, L = 0; i < s.length(); ++i) {
            ++m[s[i]];
            ++L;
            while (m.size() > k) {
                char c = s[i + 1 - L];
                if (--m[c] == 0)
                    m.erase(c);
                --L;
            }
            if (m.size() <= k && ans < L)
                ans = L;
        }
        return ans;
    }
};


class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ans = 0;
        vector<int> m(256);
        for (int i = 0, D = 0, L = 0; i < s.length(); ++i) {
            if (++m[s[i]] == 1) 
                ++D;
            ++L;
            while (D > k) {
                if (--m[s[i + 1 - L]] == 0) 
                    --D;
                --L;
            }
            if (D <= k && ans < L) 
                ans = L;
        }
        return ans;
    }
};