// 647. Palindromic Substrings

// Runtime: 4 ms, faster than 98.02% of C++ online submissions for Palindromic Substrings.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Palindromic Substrings.

// Time Complexity: O(N * N).
// Space Complexity: O(1).

class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); ++i)
            ans += count(s, i, i) + count(s, i, i + 1);
        return ans;
    }
    
    int count(const string& s, int i, int j) {
        const int N = s.length();
        int ans = 0;
        while (i >= 0 && j < N && s[i--] == s[j++]) ++ans;
        return ans;
    }
};