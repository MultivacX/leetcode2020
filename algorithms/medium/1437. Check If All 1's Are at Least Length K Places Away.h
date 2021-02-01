// 1437. Check If All 1's Are at Least Length K Places Away
// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/

// Runtime: 156 ms, faster than 62.88% of C++ online submissions for Check If All 1's Are at Least Length K Places Away.
// Memory Usage: 57.8 MB, less than 28.27% of C++ online submissions for Check If All 1's Are at Least Length K Places Away.

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        const int N = nums.size();
        int i = 0;
        while (i < N && nums[i] == 0) ++i;
        ++i;
        int zero = 0;
        while (i < N) {
            if (nums[i] == 0) {
                ++zero;
            } else if (zero < k) {
                return false;
            } else {
                zero = 0;
            }
            ++i;
        }
        return true;
    }
};