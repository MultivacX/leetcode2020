// 1974. Minimum Time to Type Word Using Special Typewriter
// https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Time to Type Word Using Special Typewriter.
// Memory Usage: 6.1 MB, less than 50.33% of C++ online submissions for Minimum Time to Type Word Using Special Typewriter.
    
class Solution {
public:
    int minTimeToType(string word) {
        const int n = word.length();
        int t = n;
        for (int i = 0, j = 'a'; i < n; ++i) {
            int k = word[i];
            t += min(abs(j - k), 26 - max(j, k) + min(j, k));
            j = k;
        }
        return t;
    }
};