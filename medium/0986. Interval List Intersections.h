// 986. Interval List Intersections

// Runtime: 60 ms, faster than 66.22% of C++ online submissions for Interval List Intersections.
// Memory Usage: 13.6 MB, less than 100.00% of C++ online submissions for Interval List Intersections.

// Runtime: O(M+N).
// Memory: O(Intersections).

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        const int M = A.size();
        const int N = B.size();
        
        vector<vector<int>> ans;
        int i = 0;
        int j = 0;
        while (i < M && j < N) {
            const auto& a = A[i];
            const auto& b = B[j];
            
            int c0 = max(a[0], b[0]);
            int c1 = min(a[1], b[1]);
            if (c0 <= c1) ans.push_back({c0, c1});
            
            if (a[1] < b[1]) ++i;
            else if (a[1] > b[1]) ++j;
            else ++i, ++j;
        }
        return ans;
    }
};