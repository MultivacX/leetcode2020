// 159. Longest Substring with At Most Two Distinct Characters
// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

// Runtime: 4 ms, faster than 89.99% of C++ online submissions for Longest Substring with At Most Two Distinct Characters.
// Memory Usage: 7 MB, less than 87.37% of C++ online submissions for Longest Substring with At Most Two Distinct Characters.
    
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        const int N = s.length();
        int a = 0, b = 0, ca = 0, cb = 0;
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            if (a != 0 && a != s[i] && b != 0 && b != s[i]) {
                int j = i - (ca + cb);
                while (j < i) {
                    if (a == s[j] && --ca == 0) {
                        a = 0;
                        break;
                    }
                    
                    if (b == s[j] && --cb == 0) {
                        b = 0;
                        break;
                    }
                    
                    ++j;
                }
            }
            
            if (a == 0 || a == s[i]) a = s[i], ++ca;
            else if (b == 0 || b == s[i]) b = s[i], ++cb;
            ans = max(ans, ca + cb);
        }
        return ans;
    }
};

// Runtime: 40 ms, faster than 8.13% of C++ online submissions for Longest Substring with At Most Two Distinct Characters.
// Memory Usage: 8.8 MB, less than 12.76% of C++ online submissions for Longest Substring with At Most Two Distinct Characters.
    
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        const int N = s.length();
        map<char, int> m; // size <= 2
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            if (m.size() == 2 && m.count(s[i]) == 0) {
                int j = i - (m.begin()->second + m.rbegin()->second);
                while (j < i) {
                    if (--m[s[j++]] == 0) {
                        m.erase(s[j - 1]);
                        break;
                    }
                }
            }
            ++m[s[i]];
            ans = max(ans, m.begin()->second + m.rbegin()->second * ((int)m.size() - 1));
        }
        return ans;
    }
};


class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int a = -1, cnt_a = 0;
        int b = -1, cnt_b = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (a == -1 || a == c) {
                a = c;
                ++cnt_a;
            } else if (b == -1 || b == c) {
                b = c;
                ++cnt_b;
            } else {
                int j = i - (cnt_a + cnt_b);
                while (cnt_a > 0 && cnt_b > 0) {
                    if (a == s[j]) --cnt_a;
                    else if (b == s[j]) --cnt_b;
                    ++j;
                }
                if (cnt_a == 0) {
                    a = c;
                    ++cnt_a;
                } else if (cnt_b == 0) {
                    b = c;
                    ++cnt_b;
                }
            }
            ans = max(ans, cnt_a + cnt_b);
        }
        return ans;
    }
};