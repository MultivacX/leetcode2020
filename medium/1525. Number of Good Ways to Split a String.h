// 1525. Number of Good Ways to Split a String
// https://leetcode.com/problems/number-of-good-ways-to-split-a-string/

// Runtime: 76 ms, faster than 75.90% of C++ online submissions for Number of Good Ways to Split a String.
// Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Number of Good Ways to Split a String.

class Solution {
public:
    int numSplits(string s) {
        const int N = s.length();
        
        vector<int> L(26, 0);
        ++L[s[0] - 'a'];
        
        vector<int> R(26, 0);
        for (int i = 1; i < N; ++i) ++R[s[i] - 'a'];
        
        int ans = 0;
        for (int i = 1; i < N; ++i) {
            int l = 0;
            int r = 0;
            for (int j = 0; j < 26; ++j) {
                if (L[j] > 0) ++l;
                if (R[j] > 0) ++r;
            }
            if (l == r) ++ans;
            
            ++L[s[i] - 'a'];
            --R[s[i] - 'a'];
        }
        return ans;
    }
};