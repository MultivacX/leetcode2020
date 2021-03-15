// 1790. Check if One String Swap Can Make Strings Equal
// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check if One String Swap Can Make Strings Equal.
// Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for Check if One String Swap Can Make Strings Equal.
    
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int j = -1, k = 0;
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] != s2[i]) {
                if (++k > 2) 
                    return false;
                if (j == -1) 
                    j = i;
                else if (s1[j] != s2[i] || s1[i] != s2[j]) 
                    return false;
            }
        }
        return k == 0 || k == 2;
    }
};