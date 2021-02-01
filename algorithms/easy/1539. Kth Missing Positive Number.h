// 1539. Kth Missing Positive Number
// https://leetcode.com/problems/kth-missing-positive-number/

// Runtime: 12 ms, faster than 34.43% of C++ online submissions for Kth Missing Positive Number.
// Memory Usage: 9.9 MB, less than 8.50% of C++ online submissions for Kth Missing Positive Number.

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cur = 0;
        for (int i = 0; i < arr.size(); ++i) {
            int dist = arr[i] - cur - 1;
            if (dist >= k) return cur + k;
            if (dist > 0) k -= dist;
            cur = arr[i];
        }
        return cur + k;
    }
};