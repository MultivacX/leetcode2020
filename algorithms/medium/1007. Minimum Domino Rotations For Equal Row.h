// 1007. Minimum Domino Rotations For Equal Row
// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

// Runtime: 276 ms, faster than 84.82% of C++ online submissions for Minimum Domino Rotations For Equal Row.
// Memory Usage: 111.9 MB, less than 5.06% of C++ online submissions for Minimum Domino Rotations For Equal Row.

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        const int N = A.size();
        vector<int> cnts(7, 0);
        for (int i = 0; i < N; ++i) {
            ++cnts[A[i]];
            if (A[i] != B[i]) 
                ++cnts[B[i]];
        }
        
        vector<int> nums;
        for (int i = 1; i <= 6; ++i)
            if (cnts[i] == N) 
                nums.push_back(i);
        if (nums.empty()) return -1;
        
        const int M = nums.size();
        vector<int> rotations2A(M, 0);
        vector<int> rotations2B(M, 0);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (A[i] == B[i]) continue;
                
                if (A[i] == nums[j]) ++rotations2B[j];
                else ++rotations2A[j];
            }
        }
        
        int ans = N;
        for (int j = 0; j < M; ++j) 
            ans = min(ans, min(rotations2A[j], rotations2B[j]));
        return ans == N ? -1 : ans;
    }
};