// 1300. Sum of Mutated Array Closest to Target
// https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(begin(arr), end(arr));
        const int N = arr.size();
        // y = k*x - t
        int ans = target;
        int diff = arr[N - 1];
        for (int i = 0; i < N; ++i) {
            int k = N - i;
            int val = target / k;
            if ((i == 0 ? 0 : arr[i - 1]) <= val && val <= arr[i]) 
                return val;
            if (diff > abs(val * k - target)) {
                ans = val;
                diff = abs(val * k - target);
            }
            target -= arr[i];
        }
        return ans;
    }
};