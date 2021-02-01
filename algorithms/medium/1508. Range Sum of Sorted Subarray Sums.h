// 1508. Range Sum of Sorted Subarray Sums
// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/submissions/

// Runtime: 868 ms, faster than 18.82% of C++ online submissions for Range Sum of Sorted Subarray Sums.
// Memory Usage: 73.2 MB, less than 5.25% of C++ online submissions for Range Sum of Sorted Subarray Sums.

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<vector<int>> sums(n, vector<int>{0, 0});
        priority_queue<int> q;
        for (int i = 0; i < n; ++i) {
            sums[i][0] = i;
            sums[i][1] = nums[i];
            q.push(nums[i]);
        }
        while (!sums.empty()) {
            vector<vector<int>> tmp;
            for (int i = 0; i < sums.size(); ++i) {
                if (sums[i][0] >= n - 1) continue;
                
                sums[i][1] = (sums[i][1] + nums[++sums[i][0]]) % 1000000007;
                if (q.size() >= right && sums[i][1] >= q.top()) continue;
                
                tmp.push_back(sums[i]);
                q.push(sums[i][1]);
                while (q.size() > right) q.pop();
            }
            swap(sums, tmp);
        }
        int ans = 0;
        while (q.size() > right) q.pop();
        while (q.size() >= left) {
            // cout << q.top() << " ";
            ans = (ans + q.top()) % 1000000007;
            q.pop();
        }
        return ans;
    }
};