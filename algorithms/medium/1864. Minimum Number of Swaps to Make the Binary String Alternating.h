// 1864. Minimum Number of Swaps to Make the Binary String Alternating
// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Number of Swaps to Make the Binary String Alternating.
// Memory Usage: 6.6 MB, less than 57.28% of C++ online submissions for Minimum Number of Swaps to Make the Binary String Alternating.
    
class Solution {
public:
    int minSwaps(string s) {
        int k0 = 0, k1 = 0;
        for (char c : s) c == '0' ? ++k0 : ++k1;
        if (abs(k0 - k1) > 1) return -1;
        
        const int n = s.length();
        
        if (k0 == k1) {
            int s0 = 0, s1 = 0;    
            for (int i = 0; i < n; i += 2) {
                if (s[i] != '0') ++s0;
                if (s[i] != '1') ++s1;
            }
            return min(s0, s1);
        }
        
        if (k0 > k1) {
            int s0 = 0;
            for (int i = 0; i < n; i += 2) 
                if (s[i] != '0') ++s0;
            return s0;
        } else {
            int s1 = 0;
            for (int i = 0; i < n; i += 2) 
                if (s[i] != '1') ++s1;
            return s1;
        }
    }
};