// 896. Monotonic Array

// Runtime: 84 ms, faster than 59.68% of C++ online submissions for Monotonic Array.
// Memory Usage: 11.8 MB, less than 100.00% of C++ online submissions for Monotonic Array.

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        const int n = A.size();
        int state = 0;
        for (int i = 1; i < n; ++i) {
            int diff = A[i] - A[i - 1];
            if (state == 1 && diff < 0) return false;
            if (state == -1 && diff > 0) return false;
            if (diff == 0) continue;
            if (state == 0) state = diff > 0 ? 1 : -1;
        }
        return true;
    }
};