// 334. Increasing Triplet Subsequence

// Runtime: 8 ms, faster than 35.89% of C++ online submissions for Increasing Triplet Subsequence.
// Memory Usage: 10.2 MB, less than 5.88% of C++ online submissions for Increasing Triplet Subsequence.

// Time Complexity: O(N).
// Space Complexity: O(1).

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        const int N = nums.size();
        if (N < 3) return false;
        
        int i = -1;
        int j = -1;
        for (int k = 0; k < N; ++k) {
            if (i < 0 || nums[i] >= nums[k]) i = k;
            else if (j < 0 || nums[j] >= nums[k]) j = k;
            else return true;
        }
        
        return false;
    }
};


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        const int n = nums.size();
        if (n < 3) return false;
        
        vector<int> mins(n, INT_MAX);
        for (int i = 0, a = nums[0]; i < n; ++i) {
            if (a > nums[i]) a = nums[i];
            if (mins[i] > a) mins[i] = a;
        }
        // for (int i : mins) cout << i << " "; cout << endl;
        for (int i = n - 2, c = nums[n - 1]; i >= 1; --i) {
            // cout << c << " ";
            if (mins[i - 1] < nums[i] && nums[i] < c) 
                return true;
            if (nums[i] > c) c = nums[i];
        }
        return false;
    }
};