// 1794. Count Pairs of Equal Substrings With Minimum Difference
// https://leetcode.com/problems/count-pairs-of-equal-substrings-with-minimum-difference/

// Runtime: 48 ms, faster than 100.00% of C++ online submissions for Count Pairs of Equal Substrings With Minimum Difference.
// Memory Usage: 15.1 MB, less than 100.00% of C++ online submissions for Count Pairs of Equal Substrings With Minimum Difference.
    
class Solution {
public:
    int countQuadruples(string firstString, string secondString) {
        vector<int> idx(128, -1);
        for (int j = 0; j < firstString.length(); ++j)
            if (idx[firstString[j]] == -1)
                idx[firstString[j]] = j;
        
        int val = INT_MAX;
        for (int a = secondString.length() - 1; a >= 0; --a) {
            int j = idx[secondString[a]];
            if (j != -1 && j - a < val)
                val = j - a;
        }
        if (val == INT_MAX) return 0;
        
        int cnt = 0;
        for (int a = secondString.length() - 1; a >= 0; --a) {
            int j = idx[secondString[a]];
            if (j != -1 && j - a == val)
                ++cnt;
        }
        return cnt;
    }
};