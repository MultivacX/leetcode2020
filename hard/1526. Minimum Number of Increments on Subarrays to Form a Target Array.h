// 1526. Minimum Number of Increments on Subarrays to Form a Target Array
// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/

// Runtime: 392 ms, faster than 47.07% of C++ online submissions for Minimum Number of Increments on Subarrays to Form a Target Array.
// Memory Usage: 73.4 MB, less than 100.00% of C++ online submissions for Minimum Number of Increments on Subarrays to Form a Target Array.

// Time Complexity: O(N).
// Space Complexity: O(1).

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        const int N = target.size();
        
        int opt = 0;
        int peak_val = -1;
        bool decreasing = false;
        for (int i = 0; i < N; ++i) {
            if (peak_val < 0) {
                peak_val = target[i];
            } else if (target[i - 1] > target[i]) {
                decreasing = true;
            } else if (target[i - 1] < target[i]) {
                if (decreasing) {
                    opt += peak_val - target[i - 1];   
                    decreasing = false;
                }
                peak_val = target[i];
            }
        }
        return opt + peak_val;
    }
};