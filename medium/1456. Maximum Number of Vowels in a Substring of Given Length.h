// 1456. Maximum Number of Vowels in a Substring of Given Length

// Runtime: 112 ms, faster than 42.40% of C++ online submissions for Maximum Number of Vowels in a Substring of Given Length.
// Memory Usage: 10.1 MB, less than 100.00% of C++ online submissions for Maximum Number of Vowels in a Substring of Given Length.

class Solution {
public:
    int maxVowels(string s, int k) {
        static const unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        const int N = s.length();
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < k; ++i) if (vowels.count(s[i])) ++cnt;
        ans = max(ans, cnt);
        for (int i = k; i < N; ++i) {
            if (vowels.count(s[i - k])) --cnt;
            if (vowels.count(s[i])) ++cnt;
            ans = max(ans, cnt);
        }
        return ans;
    }
};