// 368. Largest Divisible Subset

// Runtime: 28 ms, faster than 59.38% of C++ online submissions for Largest Divisible Subset.
// Memory Usage: 9 MB, less than 40.00% of C++ online submissions for Largest Divisible Subset.

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return nums;
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> v(n, {0, 1}); // {index, count}
        int idx = 0;
        for (int i = 1; i < n; ++i) {
            v[i][0] = i;
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] % nums[j]) continue;
                if (v[i][1] < 1 + v[j][1]) {
                    // printf("%d % %d\n", nums[i], nums[j]);
                    v[i][0] = j;
                    v[i][1] = 1 + v[j][1];
                    if (v[i][1] > v[idx][1])
                        idx = i;
                }
            }
        }
        
        vector<int> ans{nums[idx]};
        while (idx != v[idx][0]) {
            idx = v[idx][0];
            ans.push_back(nums[idx]);
        }
        return ans;
    }
};