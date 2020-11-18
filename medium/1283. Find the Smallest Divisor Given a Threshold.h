// 1283. Find the Smallest Divisor Given a Threshold
// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

// Runtime: 64 ms, faster than 80.47% of C++ online submissions for Find the Smallest Divisor Given a Threshold.
// Memory Usage: 20.4 MB, less than 56.62% of C++ online submissions for Find the Smallest Divisor Given a Threshold.

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans = INT_MAX;
        int diff = INT_MAX;
        int l = 1;
        int r = *max_element(begin(nums), end(nums));
        while (l <= r) {
            int m = l + (r - l) / 2;
            int sum = 0;
            for (int i : nums) sum += ceil((double)i / (double)m);
            // if (sum == threshold) return m;
            if (sum > threshold) {
                l = m + 1;
            } else {
                // cout << m << " " << sum << " " << threshold - sum << endl;
                r = m - 1;
                if (diff >= threshold - sum) {
                    if (diff == threshold - sum && ans > m) ans = m;
                    if (diff > threshold - sum) ans = m;
                    diff = threshold - sum;
                }
            }
        }
        return ans;
    }
};