// 801. Minimum Swaps To Make Sequences Increasing
// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/

// Runtime: 32 ms, faster than 24.68% of C++ online submissions for Minimum Swaps To Make Sequences Increasing.
// Memory Usage: 14.2 MB, less than 84.21% of C++ online submissions for Minimum Swaps To Make Sequences Increasing.

// Time Complexity: O(N).
// Space Complexity: O(1).

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        const int N = A.size();
        
        // vector<int> swaped(N, N);
        // vector<int> no_swaped(N, N);
        
        // swaped[0] = 1;
        // no_swaped[0] = 0;
        int swaped = 1;
        int no_swaped = 0;
       
        for (int i = 1; i < N; ++i) {
            int swaped_cur = N;
            int no_swaped_cur = N;
            
            if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
                // swaped[i] = 1 + swaped[i - 1];
                // no_swaped[i] = no_swaped[i - 1];
                swaped_cur = 1 + swaped;
                no_swaped_cur = no_swaped;
            }

            if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
                // swaped[i] = min(swaped[i], 1 + no_swaped[i - 1]);
                // no_swaped[i] = min(no_swaped[i], swaped[i - 1]);
                swaped_cur = min(swaped_cur, 1 + no_swaped);
                no_swaped_cur = min(no_swaped_cur, swaped);
            }
            
            swaped = swaped_cur;
            no_swaped = no_swaped_cur;
        }
        
        // return min(swaped.back(), no_swaped.back());
        return min(swaped, no_swaped);
    }
};