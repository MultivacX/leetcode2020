// 644. Maximum Average Subarray II

// TLE: O(n*n)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        const int N = nums.size();
        vector<double> s(N + 1, 0);
        double max_avg = INT_MIN;
        for (int i = 0; i < N; ++i) {
            s[i + 1] = s[i] + nums[i];
            for (int j = 0; j <= i + 1 - k; ++j) {
                max_avg = max(max_avg, (s[i + 1] - s[j]) / (i + 1 - j));
                // cout << (s[i + 1] - s[j]) / (i + 1 - j) << endl;
            }
        }
        return max_avg;
    }
};