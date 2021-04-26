// 1838. Frequency of the Most Frequent Element
// https://leetcode.com/problems/frequency-of-the-most-frequent-element/

// Runtime: 272 ms, faster than 30.77% of C++ online submissions for Frequency of the Most Frequent Element.
// Memory Usage: 86.2 MB, less than 7.69% of C++ online submissions for Frequency of the Most Frequent Element.
    
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // [j, i] == nums[i], presum[i+1] == sum([0, i])
        // nums[i] * (i - (j - 1)) <= k + presum[i+1] - presum[j]
        
        sort(begin(nums), end(nums));
        
        const int n = nums.size();
        int ans = 1;
        vector<int64_t> presum(n + 1);
        for (int i = 0; i < n; ++i) {
            presum[i + 1] = presum[i] + nums[i];

            int l = 0, r = i;
            while (l < r) {
                int j = l + (r - l) / 2;
                // cout << j << ", " << i << ": " 
                //      << nums[i] * (i - (j - 1)) << " <> " 
                //      << k + presum[i + 1] - presum[j] << endl;
                if (nums[i] * (int64_t)(i - (j - 1)) <= k + presum[i + 1] - presum[j])
                    r = j, ans = max(ans, i - (j - 1));
                else
                    l = j + 1;
            }
        }
        return ans;
    }
};