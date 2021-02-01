// 1566. Detect Pattern of Length M Repeated K or More Times
// https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/

// Runtime: 4 ms, faster than 79.42% of C++ online submissions for Detect Pattern of Length M Repeated K or More Times.
// Memory Usage: 8.4 MB, less than 31.53% of C++ online submissions for Detect Pattern of Length M Repeated K or More Times.

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        // 0 <= i < N, 1 <= j <= k
        // i + k * m <= N
        // [i + j * m - m, i + j * m)
        const int N = arr.size();
        int i = 0;
        while (i + k * m <= N) {
            bool same = true;
            int l = 1;
            while (same && l <= m) {
                // printf("[%d]:%d ", i, arr[i]);
                int j = 2;
                for (; same && j <= k; ++j) {
                    // printf("[%d]:%d ", i + j * m - m, arr[i + j * m - m]);
                    if (arr[i] == arr[i + j * m - m]) continue;
                    same = false;
                }
                // cout << endl;
                ++l;
                ++i;
            }
            if (same) return true;
        }
        return false;
    }
};