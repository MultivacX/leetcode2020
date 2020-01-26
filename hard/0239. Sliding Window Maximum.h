// 239. Sliding Window Maximum

// Runtime: 84 ms, faster than 22.24% of C++ online submissions for Sliding Window Maximum.
// Memory Usage: 13.6 MB, less than 31.15% of C++ online submissions for Sliding Window Maximum.

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return nums;
        
        auto cmp = [&nums](int a, int b) { return nums[a] < nums[b]; };
        using Q = priority_queue<int, vector<int>, decltype(cmp)>;
		Q q(cmp);
        
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < k - 1) {
                q.push(i);
            } else if (nums[i] >= nums[q.top()]) {
                q.push(i);
                ans.push_back(nums[i]);
            } else {
                q.push(i);
                while (!q.empty() && i - q.top() >= k) q.pop();
                ans.push_back(nums[q.top()]);
            }
        }
        return ans;
    }
};