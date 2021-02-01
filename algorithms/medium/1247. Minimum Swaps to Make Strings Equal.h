// 1247. Minimum Swaps to Make Strings Equal
// https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/

// Runtime: 4 ms, faster than 50.23% of C++ online submissions for Minimum Swaps to Make Strings Equal.
// Memory Usage: 6.4 MB, less than 32.26% of C++ online submissions for Minimum Swaps to Make Strings Equal.

// Time Complexity: O(N).
// Space Complexity: O(1).

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        // xx yy -> 1 -> xy xy
        // xy yx -> 2 -> xy xy
        
        const int N = s1.length();
        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;
        for (int i = 0; i < N; ++i) {
            if (s1[i] == s2[i]) continue;
            
            if (s1[i] == 'x') ++x1;
            else ++y1;
            
            if (s2[i] == 'x') ++x2;
            else ++y2;
        }
        if (((x1 + x2) & 1) || ((y1 + y2) & 1)) return -1;
        return x1 / 2 + y1 / 2 + ((x1 & 1) ? 2 : 0);
    }
};