
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