// 790. Domino and Tromino Tiling
// https://leetcode.com/problems/domino-and-tromino-tiling/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Domino and Tromino Tiling.
// Memory Usage: 7.6 MB, less than 18.00% of C++ online submissions for Domino and Tromino Tiling.

class Solution {
public:
    int numTilings(int N) {
        if (N <= 2) return N;
        
        // ...X
        // ...X
        vector<int64_t> rects1(N + 1, 0); rects1[1] = rects1[2] = 1;
        // ..XX
        // ..ZZ
        vector<int64_t> rects2(N + 1, 0); rects2[2] = 1;
        // ..XX
        // ...X
        vector<int64_t> rects3(N + 1, 0);
        // ...X
        // ..XX
        vector<int64_t> rects4(N + 1, 0);
        
        // ..O
        // ..OO
        vector<int64_t> L1(N + 1, 0); L1[2] = 1;
        // ..OO
        // ..O
        vector<int64_t> L2(N + 1, 0); L2[2] = 1;
        
        for (int i = 3; i <= N; ++i) {
            rects1[i] = (rects1[i - 1] + rects2[i - 1] + rects3[i - 1] + rects4[i - 1]) % 1000000007;
            rects2[i] = (rects1[i - 2] + rects2[i - 2] + rects3[i - 2] + rects4[i - 2]) % 1000000007;
            rects3[i] = L1[i - 1];
            rects4[i] = L2[i - 1];
            
            L1[i] = (L2[i - 1] + rects1[i - 2] + rects2[i - 2] + rects3[i - 2] + rects4[i - 2]) % 1000000007;
            L2[i] = (L1[i - 1] + rects1[i - 2] + rects2[i - 2] + rects3[i - 2] + rects4[i - 2]) % 1000000007;
            
            // cout << rects1[i] << " " << rects2[i] << " " << rects3[i] << " " << rects4[i] << endl;
        }
        
        return (rects1[N] + rects2[N] + rects3[N] + rects4[N]) % 1000000007;
    }
};