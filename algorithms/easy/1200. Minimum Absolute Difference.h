// 1200. Minimum Absolute Difference
// https://leetcode.com/problems/minimum-absolute-difference/

// Runtime: 276 ms, faster than 8.00% of C++ online submissions for Minimum Absolute Difference.
// Memory Usage: 32.7 MB, less than 33.27% of C++ online submissions for Minimum Absolute Difference.

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(begin(arr), end(arr));
        int diff = INT_MAX;
        for (int i = 0; i + 1 < arr.size(); ++i) {
            int d = arr[i + 1] - arr[i];
            if (d < diff) {
                diff = d;
                ans.clear();
                ans.push_back({arr[i], arr[i + 1]});
            } else if (d == diff) {
                ans.push_back({arr[i], arr[i + 1]});
            }
        }
        return ans;
    }
};