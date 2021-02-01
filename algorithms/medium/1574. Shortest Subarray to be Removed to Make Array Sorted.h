// 1574. Shortest Subarray to be Removed to Make Array Sorted
// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/

// Runtime: 320 ms, faster than 35.66% of C++ online submissions for Shortest Subarray to be Removed to Make Array Sorted.
// Memory Usage: 69 MB, less than 18.08% of C++ online submissions for Shortest Subarray to be Removed to Make Array Sorted.

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        const int N = arr.size();
        if (N <= 1) return 0;

        int ans = N - 1;
        // 1. arr[0, i] & 0 <= i < N & remove subarray arr[i+1, N)
        vector<int> left{arr[0]};
        for (int i = 1; i < N; ++i) {
            if (arr[i] < arr[i - 1]) break;
            left.push_back(arr[i]);
            ans = min(ans, N - 1 - i);
        }
        if (ans == 0) return ans;

        // 2. arr[j, N) & 0 <  j < N & remove subarray arr[0, j)
        vector<int> right{arr[N - 1]};
        for (int j = N - 2; j > 0; --j) {
            if (arr[j] > arr[j + 1]) break;
            right.push_back(arr[j]);
            ans = min(ans, j);
        }
        if (ans == 1) return ans;

        reverse(begin(right), end(right));

        // for (int v : left) cout << v << ", ";
        // cout << "     ";
        // for (int v : right) cout << v << ", ";
        // cout << endl;

        // 3. arr[0, i]...arr[j, N) & 0 <= i < j < N & i + 1 <= j - 1 & remove subarray arr[i+1, j-1]
        for (int i = 0; i < left.size(); ++i) {
            int l = left[i];
            auto it = lower_bound(begin(right), end(right), l); // optim: use stack
            if (it == end(right)) break;
            int j = it - begin(right) + (N - right.size());
            ans = min(ans, j - i - 1);
        }

        return ans;
    }
};