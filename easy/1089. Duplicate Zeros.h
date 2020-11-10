// 1089. Duplicate Zeros
// https://leetcode.com/problems/duplicate-zeros/

// Runtime: 8 ms, faster than 94.85% of C++ online submissions for Duplicate Zeros.
// Memory Usage: 9.9 MB, less than 100.00% of C++ online submissions for Duplicate Zeros.

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        const int N = arr.size();
        for (int i = 0, k = 0; i < N; ++i) {
            int t = k;
            if (arr[i] == 0) ++k;
            arr[i] |= (t << 4);
        }
        for (int i = N - 1; i >= 0; --i) {
            int k = arr[i] >> 4;
            arr[i] = arr[i] - (k << 4);
            int j = i + k;
            if (j < N) {
                arr[j] = arr[i];
                if (arr[i] == 0 && j + 1 < N) arr[j + 1] = 0;
            }
        }
    }
};