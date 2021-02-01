// 259. 3Sum Smaller
// https://leetcode.com/problems/3sum-smaller/

// Runtime: 8 ms, faster than 98.83% of C++ online submissions for 3Sum Smaller.
// Memory Usage: 13.3 MB, less than 63.59% of C++ online submissions for 3Sum Smaller.
    
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        const int N = nums.size();
        int cnt = 0;
        auto count = [&](int i, int t) {
            int j = i + 1, k = N - 1;
            // nums[i] + nums[j] + nums[j+1,...,k]
            while (j < k)
                if (nums[j] + nums[k] < t)
                    cnt += k - j++;
                else --k;
        };
        for (int i = 0; i < N - 2; ++i)
            count(i, target - nums[i]);
        return cnt;
    }
};