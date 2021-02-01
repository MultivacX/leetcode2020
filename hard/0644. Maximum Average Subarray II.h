// 644. Maximum Average Subarray II
// https://leetcode.com/problems/maximum-average-subarray-ii/

// Runtime: 152 ms, faster than 81.51% of C++ online submissions for Maximum Average Subarray II.
// Memory Usage: 37.9 MB, less than 96.64% of C++ online submissions for Maximum Average Subarray II.
    
class Solution {
    bool find(vector<int>& nums, int k, double target) {
        const int N = nums.size();
        double sum = 0;
        double pre = 0;
        double minSum = 0;
        for (int i = 0; i < N; ++i) {
            if (i >= k) {
                pre += (double)nums[i - k] - target;
                minSum = min(minSum, pre);
            }
            
            sum += (double)nums[i] - target;
            // target is small
            if (i + 1 >= k && sum > minSum) 
                return false;
        }
        return true;
    }
    
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double l = *min_element(begin(nums), end(nums));
        double r = *max_element(begin(nums), end(nums));
        while (l + 0.00001 < r) {
            // cout << l << " " << r << endl;
            double m = l + (r - l) / 2.0;
            if (find(nums, k, m)) r = m;
            // target is small
            else l = m;
        }
        return l;
    }
};