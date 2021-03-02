// 15. 3Sum

// Runtime: 372 ms, faster than 9.20% of C++ online submissions for 3Sum.
// Memory Usage: 14.6 MB, less than 97.06% of C++ online submissions for 3Sum.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            
            for (int j = i + 1; j < n - 1; ++j) {
                if (j > i + 1 && nums[j - 1] == nums[j]) continue;
                
                int target = -nums[i] - nums[j];
                if (binary_search(nums.begin() + j + 1, nums.end(), target)) {
                    ans.push_back({nums[i], nums[j], target});
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int n = nums.size();
        sort(begin(nums), end(nums));
        
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; ++i) {
            if (i != 0 && nums[i - 1] == nums[i])
                continue;
            int target = -nums[i];
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (nums[j] + nums[k] == target) {
                    if (!(j > i + 1 && nums[j - 1] == nums[j])) {
                       ans.push_back({nums[i], nums[j], nums[k]});
                    }
                    ++j; --k;
                } else if (nums[j] + nums[k] > target) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        return ans;
    }
};