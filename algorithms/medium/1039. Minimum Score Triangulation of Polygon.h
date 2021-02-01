// 1039. Minimum Score Triangulation of Polygon
// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

// Runtime: 12 ms, faster than 38.55% of C++ online submissions for Minimum Score Triangulation of Polygon.
// Memory Usage: 9 MB, less than 8.57% of C++ online submissions for Minimum Score Triangulation of Polygon.

class Solution {
    int getScore(vector<int>& A, vector<vector<int>>& dp, int start, int end) {
        if (start + 1 >= end) return 0;
        if (dp[start][end] > 0) return dp[start][end];
        
        int score = INT_MAX;
        for (int k = start + 1; k < end; ++k)
            score = min(score, getScore(A, dp, start, k) + getScore(A, dp, k, end) + A[start] * A[k] * A[end]);
        dp[start][end] = score;
        return score;
    }
    
public:
    int minScoreTriangulation(vector<int>& A) {
        const int N = A.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));
        return getScore(A, dp, 0, N - 1);
    }
};

// Time Limit Exceeded
class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        const int N = A.size();
        vector<int> points(N, 0);
        for (int i = 0; i < N; ++i) 
            points[i] = i;
        return get_score(A, points);
    }
    
    map<vector<int>, int64_t> m;
    
    int64_t get_score(const vector<int>& A, vector<int>& points) {
        const int N = points.size();
        if (N < 3) return 0;
        if (N == 3) return A[points[0]] * A[points[1]] * A[points[2]];
        if (N == 4) return min(A[points[0]] * A[points[1]] * A[points[2]] + A[points[0]] * A[points[2]] * A[points[3]],
                               A[points[0]] * A[points[1]] * A[points[3]] + A[points[1]] * A[points[2]] * A[points[3]]);
        
        if (m.count(points)) return m[points];
        
        int64_t score = INT_MAX;
        for (int i = 2; i <= N - 2; ++i) {
            if (N - i + 1 < 3) continue;
            vector<int> L(points.begin(), points.begin() + i + 1);
            vector<int> R(points.begin() + i, points.end());
            R.push_back(points[0]);
            
            score = min(score, get_score(A, L) + get_score(A, R));
        }
        m[points] = score;
        return score;
    }
};