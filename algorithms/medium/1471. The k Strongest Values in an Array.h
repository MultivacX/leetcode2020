// 1471. The k Strongest Values in an Array
// https://leetcode.com/problems/the-k-strongest-values-in-an-array/

// Runtime: 436 ms, faster than 94.47% of C++ online submissions for The k Strongest Values in an Array.
// Memory Usage: 80.6 MB, less than 9.96% of C++ online submissions for The k Strongest Values in an Array.

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(begin(arr), end(arr));
        const int N = arr.size();
        int m = arr[(N - 1) / 2];
        vector<int> ans(k);
        int i = 0;
        int j = N - 1;
        int x = 0;
        while (x < k) ans[x++] = arr[m - arr[i] <= arr[j] - m ? j-- : i++];
        return ans;
    }
};