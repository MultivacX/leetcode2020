// 941. Valid Mountain Array

// Runtime: 32 ms, faster than 96.86% of C++ online submissions for Valid Mountain Array.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Valid Mountain Array.

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        const int n = A.size();
        if (n < 3) return false;
        
        int i = 0;
        while (i < n - 1) {
            if (A[i] == A[i + 1]) return false;
            if (A[i] > A[i + 1]) break;
            ++i;
        }
        if (i == 0) return false;
        
        int j = n - 1;
        while (j > i) {
            if (A[j] == A[j - 1]) return false;
            if (A[j] > A[j - 1]) break;
            --j;
        }
        if (j == n - 1) return false;
        
        return i == j;
    }
};