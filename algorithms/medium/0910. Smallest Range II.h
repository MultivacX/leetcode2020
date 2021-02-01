// 910. Smallest Range II
// https://leetcode.com/problems/smallest-range-ii/

// Runtime: 56 ms, faster than 36.06% of C++ online submissions for Smallest Range II.
// Memory Usage: 16 MB, less than 9.13% of C++ online submissions for Smallest Range II.
    
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        // A[i] - a, A[i] + b
        //
        // A[i] + (b + a)
        
        sort(begin(A), end(A));
        int minA = A.front();
        int maxA = A.back(); 
        int ans = maxA - minA;
        for (int i = 0, B0 = A[0] + 2 * K; i + 1 < A.size(); ++i) {
            int Bi = A[i] + 2 * K;
            minA = min(B0, min(Bi, A[i + 1]));
            maxA = max(Bi, A.back());
            ans = min(ans, maxA - minA);
            // cout << Bi << ":" << minA << ", " << maxA << endl;
        }
        return ans;
    }
};