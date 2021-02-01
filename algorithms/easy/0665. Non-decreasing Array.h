// 665. Non-decreasing Array
// https://leetcode.com/problems/non-decreasing-array/submissions/

// Runtime: 48 ms, faster than 65.63% of C++ online submissions for Non-decreasing Array.
// Memory Usage: 26.9 MB, less than 5.00% of C++ online submissions for Non-decreasing Array.

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        const int N = nums.size();
        int idx = -1;
        // nums[i] <= nums[i + 1] 
        for (int i = 0; i + 1 < N; ++i) {
            if (nums[i] <= nums[i + 1]) continue;
            if (idx >= 0) return false;
            
            if (i == 0) {
                idx = 0;
            } else if (i == N - 2) {
                idx = N - 1;    
            } else {
                idx = i;
            }
        }
        // cout << idx << endl;
        return idx < 0 || idx == 0 || idx == N - 1 || nums[idx - 1] <= nums[idx + 1] || nums[idx] <= nums[idx + 2];
    }
};