// 976. Largest Perimeter Triangle
// https://leetcode.com/problems/largest-perimeter-triangle/

// Runtime: 88 ms, faster than 81.12% of C++ online submissions for Largest Perimeter Triangle.
// Memory Usage: 22.3 MB, less than 5.27% of C++ online submissions for Largest Perimeter Triangle.

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(begin(A), end(A));
        for (int i = A.size() - 1; i >= 2; --i) 
            if(A[i] < A[i - 1] + A[i - 2])
                return A[i] + A[i - 1] + A[i - 2];
        return 0;
    }
};