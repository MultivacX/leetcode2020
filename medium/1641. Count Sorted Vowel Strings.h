// 1641. Count Sorted Vowel Strings
// https://leetcode.com/problems/count-sorted-vowel-strings/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Sorted Vowel Strings.
// Memory Usage: 6.3 MB, less than 37.48% of C++ online submissions for Count Sorted Vowel Strings.

class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> cnts{1, 1, 1, 1, 1};
        for (int i = 2; i <= n; ++i) {
            cnts[0] = cnts[0] + cnts[1] + cnts[2] + cnts[3] + cnts[4];
            cnts[1] =           cnts[1] + cnts[2] + cnts[3] + cnts[4];
            cnts[2] =                     cnts[2] + cnts[3] + cnts[4];
            cnts[3] =                               cnts[3] + cnts[4];
            cnts[4] =                                         cnts[4];
        }
        return cnts[0] + cnts[1] + cnts[2] + cnts[3] + cnts[4];
    }
};