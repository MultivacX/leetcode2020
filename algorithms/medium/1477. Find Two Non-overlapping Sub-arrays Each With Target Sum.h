// 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/

// Runtime: 244 ms, faster than 93.87% of C++ online submissions for Find Two Non-overlapping Sub-arrays Each With Target Sum.
// Memory Usage: 77.3 MB, less than 40.00% of C++ online submissions for Find Two Non-overlapping Sub-arrays Each With Target Sum.

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        const int N = arr.size();
        
        vector<int> L(N, INT_MAX);
        for (int i = 0, start = 0, sum = 0, len = INT_MAX; i < N; ++i) {
            sum += arr[i];
            while (sum > target)
                sum -= arr[start++];
            if (sum == target) {
                len = min(len, i - start + 1);
                sum -= arr[start++];
            }
            L[i] = len;
        }
        
        vector<int> R(N, INT_MAX);
        for (int i = N - 1, start = N - 1, sum = 0, len = INT_MAX; i >= 0; --i) {
            sum += arr[i];
            while (sum > target)
                sum -= arr[start--];
            if (sum == target) {
                len = min(len, start - i + 1);
                sum -= arr[start--];
            }
            R[i] = len;
        }
        
        // for (int i : L) cout << (i == INT_MAX ? 0 : i) << " "; cout << endl;
        // for (int i : R) cout << (i == INT_MAX ? 0 : i) << " "; cout << endl;
        
        int ans = -1;
        for (int i = 0; i < N - 1; ++i) {
            if (L[i] == INT_MAX || R[i + 1] == INT_MAX) continue;
            if (ans == -1) ans = L[i] + R[i + 1];
            else ans = min(ans, L[i] + R[i + 1]);
        }
        return ans;
    }
};