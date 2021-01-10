// 469. Convex Polygon
// https://leetcode.com/problems/convex-polygon/

// Runtime: 72 ms, faster than 88.64% of C++ online submissions for Convex Polygon.
// Memory Usage: 19.7 MB, less than 86.36% of C++ online submissions for Convex Polygon.
    
class Solution {
    int getNormalZ(const vector<int>& A, const vector<int>& B, const vector<int>& C) {
        int abx = B[0] - A[0], aby = B[1] - A[1];
        int acx = C[0] - A[0], acy = C[1] - A[1];
        return abx * acy - acx * aby;
    }
    
public:
    bool isConvex(vector<vector<int>>& points) {
        const int N = points.size();
        int z = getNormalZ(points[0], points[1], points[2]);
        for (int i = 1; i < N; ++i) {
            int t = getNormalZ(points[i], points[(i + 1) % N], points[(i + 2) % N]);
            if (z == 0) z = t;
            if (t == 0) continue;
            if (z > 0 && t < 0) return false;
            if (z < 0 && t > 0) return false;
        }
        return true;
    }
};