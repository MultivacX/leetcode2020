// 1704. Determine if String Halves Are Alike
// https://leetcode.com/problems/determine-if-string-halves-are-alike/

// Runtime: 8 ms, faster than 33.71% of C++ online submissions for Determine if String Halves Are Alike.
// Memory Usage: 7.1 MB, less than 20.53% of C++ online submissions for Determine if String Halves Are Alike.
    
class Solution {
public:
    bool halvesAreAlike(string s) {
        static const unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        const int N = s.length();
        int ans = 0;
        for (int i = 0, j = N / 2; i < N / 2; ++i, ++j) {
            if (vowels.count(s[i])) ++ans;
            if (vowels.count(s[j])) --ans;
        }
        return ans == 0;
    }
};