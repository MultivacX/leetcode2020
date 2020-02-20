// 223. Rectangle Area

// Runtime: 12 ms, faster than 65.98% of C++ online submissions for Rectangle Area.
// Memory Usage: 8.2 MB, less than 78.26% of C++ online submissions for Rectangle Area.

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int64_t area = int64_t(C - A) * int64_t(D - B) + int64_t(G - E) * int64_t(H - F);
        int l = max(A, E);
        int b = max(B, F);
        int r = min(C, G);
        int t = min(D, H);
        return area - (l < r && b < t ? (r - l) * (t - b) : 0);
    }
};