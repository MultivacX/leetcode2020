// 1941. Check if All Characters Have Equal Number of Occurrences
// https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check if All Characters Have Equal Number of Occurrences.
// Memory Usage: 6.7 MB, less than 84.25% of C++ online submissions for Check if All Characters Have Equal Number of Occurrences.
    
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        array<int, 26> cnt{0};
        int k = 0;
        for (char c : s)
            k = max(k, ++cnt[c - 'a']);
        for (int i : cnt)
            if (i != 0 && i != k)
                return false;
        return true;
    }
};