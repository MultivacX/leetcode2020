// 1198. Find Smallest Common Element in All Rows
// https://leetcode.com/problems/find-smallest-common-element-in-all-rows/

// Runtime: 140 ms, faster than 71.75% of C++ online submissions for Find Smallest Common Element in All Rows.
// Memory Usage: 25 MB, less than 38.57% of C++ online submissions for Find Smallest Common Element in All Rows.
    
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        const int M = mat.size();
        const int N = mat[0].size();
        unordered_set<int> s(begin(mat[0]), end(mat[0]));
        for (int i = 1; i < M; ++i) {
            unordered_set<int> t;
            for (int j = 0; j < N; ++j) {
                if (!s.count(mat[i][j]))
                    continue;
                t.insert(mat[i][j]);
            }
            s = t;
        }
        int ans = INT_MAX;
        for (int i : s) if (ans > i) ans = i;
        return ans == INT_MAX ? -1 : ans;
    }
};