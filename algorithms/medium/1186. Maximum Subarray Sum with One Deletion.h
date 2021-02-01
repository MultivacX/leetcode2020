// 1186. Maximum Subarray Sum with One Deletion

// Runtime: 44 ms, faster than 60.54% of C++ online submissions for Maximum Subarray Sum with One Deletion.
// Memory Usage: 12.7 MB, less than 100.00% of C++ online submissions for Maximum Subarray Sum with One Deletion.

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        const int N = arr.size();
        if (N == 1) return arr[0];
        
        int ans = arr[0];
        
        // sum[0 ... i]
        vector<int> l(N, 0);
        l[0] = arr[0];
        int sum = arr[0];
        for (int i = 1; i < N; ++i) {
            sum += arr[i];
            if (sum < arr[i]) sum = arr[i];
            l[i] = sum;
            ans = max(ans, sum);
        }
        
        // sum[i ... N - 1]
        vector<int> r(N, 0);
        r[N - 1] = arr[N - 1];
        sum = arr[N - 1];
        for (int i = N - 2; i >= 0; --i) {
            sum += arr[i];
            if (sum < arr[i]) sum = arr[i];
            r[i] = sum;
        }
        
        for (int i = 1; i < N - 1; ++i) {
            ans = max(ans, l[i - 1] + r[i + 1]);
        }
        return ans;
    }
};