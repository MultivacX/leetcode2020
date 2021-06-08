// 1888. Minimum Number of Flips to Make the Binary String Alternating
// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/

// Runtime: 100 ms, faster than 20.09% of C++ online submissions for Minimum Number of Flips to Make the Binary String Alternating.
// Memory Usage: 11.3 MB, less than 98.57% of C++ online submissions for Minimum Number of Flips to Make the Binary String Alternating.
    
class Solution {
public:
    int minFlips(string s) {
        const int n = s.length();
        int k1 = 0, k2 = 0, k = n;
        for (int i = 0; i < n * 2; ++i) {
            int j = i % n;
            
            // Type-2: flip
            // s1 = "01..."
            char c1 = i % 2 == 0 ? '0' : '1';
            if (c1 != s[j]) ++k1;
            
            // s1 = "10..."
            char c2 = i % 2 == 0 ? '1' : '0';
            if (c2 != s[j]) ++k2;
            
            // Type-1:
            // if flipped at i-n
            if (i >= n) {
                j = i - n;
                
                c1 = j % 2 == 0 ? '0' : '1';
                if (c1 != s[j]) --k1;
                
                c2 = j % 2 == 0 ? '1' : '0';
                if (c2 != s[j]) --k2;
            }
            
            if (i >= n - 1) k = min({k1, k2, k});
        }
        return k;
    }
};