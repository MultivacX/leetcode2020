// 18. 4Sum

// Runtime: 36 ms, faster than 67.41% of C++ online submissions for 4Sum.
// Memory Usage: 9.1 MB, less than 96.49% of C++ online submissions for 4Sum.

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 3; ++i) {
            int a = nums[i];
            if (i > 0 && nums[i - 1] == a) continue;
            for (int j = i + 1; j < n - 2; ++j) {
                int b = nums[j];
                if (j > i + 1 && nums[j - 1] == b) continue;
                
                int k = j + 1;
                int l = n - 1;
                while (k < l) {
                    int c = nums[k];
                    if (k > j + 1 && nums[k - 1] == c) {
                        ++k;
                        continue;
                    }
                    
                    int d = nums[l];
                    if (l < n - 1 && nums[l + 1] == d) {
                        --l;
                        continue;
                    }
                    
                    int sum = a + b + c + d;
                    if (sum == target) {
                        ans.push_back({a, b, c, d});
                        ++k;
                        --l;
                    } else if (sum < target) {
                        ++k;
                    } else {
                        --l;
                    }
                }
            }
        }
        return ans;
    }
};