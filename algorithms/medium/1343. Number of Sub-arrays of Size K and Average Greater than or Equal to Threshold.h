// 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

// Runtime: 120 ms, faster than 53.84% of C++ online submissions for Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold.
// Memory Usage: 14 MB, less than 100.00% of C++ online submissions for Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold.

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int64_t sum = accumulate(begin(arr), begin(arr) + k, 0);
        int64_t target = k * threshold;
        int cnt = sum >= target ? 1 : 0;
        for (int i = k; i < arr.size(); ++i) {
            sum = sum - arr[i - k] + arr[i];
            cnt += sum >= target ? 1 : 0;
        }
        return cnt;
    }
};