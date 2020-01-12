// 978. Longest Turbulent Subarray

// Runtime: 112 ms, faster than 44.10% of C++ online submissions for Longest Turbulent Subarray.
// Memory Usage: 13.3 MB, less than 100.00% of C++ online submissions for Longest Turbulent Subarray.

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size();
        if (n <= 1) return n;
        int len = 1;
        int k = -1;
        int flag = 0; // -1, 1
        for (int i = 0; i < n - 1; ++i) {
            if (A[i] == A[i + 1]) {
                if (k != -1) len = max(len, i - k + 1);
                k = -1;
                flag = 0;
            } else if (A[i] < A[i + 1]) {
                if (k == -1) {
                    k = i;
                    flag = 1;
                    len = max(len, 2);
                } else if (flag == -1) {
                    flag = 1;
                    len = max(len, i + 1 - k + 1);
                } else {
                    k = i;
                    flag = 1;
                    len = max(len, i - k + 1);
                }
            } else {
                if (k == -1) {
                    k = i;
                    flag = -1;
                    len = max(len, 2);
                } else if (flag == 1) {
                    flag = -1;
                    len = max(len, i + 1 - k + 1);
                } else {
                    k = i;
                    flag = -1;
                    len = max(len, i - k + 1);
                }
            }
        }
        return len;
    }
};