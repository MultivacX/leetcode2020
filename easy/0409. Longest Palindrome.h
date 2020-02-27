// 409. Longest Palindrome

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Palindrome.
// Memory Usage: 8.8 MB, less than 80.00% of C++ online submissions for Longest Palindrome.

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cnt(128, 0);
        for (const auto& c : s)
            ++cnt[c];
        // cout << accumulate(cnt.begin(), cnt.end(), 0) << " == " << s.length() << endl;
        // for (int i = 0; i < 128; ++i) if (cnt[i]) printf("%c:%d ", i, cnt[i]);
        int ans = 0;
        int max_odd = 0;
        bool max_odd_used = false;
        for (int i : cnt) {
            if (i & 1) {
                max_odd = max(max_odd, i);
            } else {
                ans += i;
            }
        }
        for (int i : cnt) {
            if (i == max_odd && !max_odd_used) {
                ans += max_odd;
                max_odd_used = true;
            } else if (i & 1) {
                ans += i - 1;
            }
        }
        return ans;
    }
};