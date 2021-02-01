// 717. 1-bit and 2-bit Characters
// https://leetcode.com/problems/1-bit-and-2-bit-characters/

// Runtime: 8 ms, faster than 64.82% of C++ online submissions for 1-bit and 2-bit Characters.
// Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for 1-bit and 2-bit Characters.

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        const int N = bits.size();
        // [0] [0, 0]
        if (N <= 2) return bits[0] == 0;
        
        vector<bool> b(N, false);
        b[0] = !bits[0];
        b[1] = (!bits[0] && !bits[1]) || bits[0];
        for (int i = 2; i + 1 < N; ++i) {
            b[i] = (b[i - 1] && bits[i] == 0) || 
                   (b[i - 2] && bits[i - 1]);
        }
        return b[N - 2];
    }
};