// 58. Length of Last Word

// Runtime: 8 ms, faster than 57.22% of C++ online submissions for Length of Last Word.
// Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Length of Last Word.

// Time Complexity: O(1).
// Space Complexity: O(1).

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        const int N = s.length();
        int i = N - 1;
        while (i >= 0 && s[i] == ' ') --i;
        while (i >= 0 && s[i] != ' ') ++ans, --i;
        return ans;
    }
};