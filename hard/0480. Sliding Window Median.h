// 480. Sliding Window Median

// Runtime: 160 ms, faster than 18.78% of C++ online submissions for Sliding Window Median.
// Memory Usage: 12.6 MB, less than 100.00% of C++ online submissions for Sliding Window Median.

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        vector<int> w;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < k) {
                w.push_back(nums[i]);
                if (i == k - 1) {
                    sort(w.begin(), w.end());
                    ans.push_back(k % 2 ? w[k / 2] : (w[k / 2 - 1] / 2.0 + w[k / 2] / 2.0));
                }
            } else {
                w.erase(lower_bound(w.begin(), w.end(), nums[i - k]));
                w.insert(lower_bound(w.begin(), w.end(), nums[i]), nums[i]);
                ans.push_back(k % 2 ? w[k / 2] : (w[k / 2 - 1] / 2.0 + w[k / 2] / 2.0));
            }
        }
        return ans;
    }
};