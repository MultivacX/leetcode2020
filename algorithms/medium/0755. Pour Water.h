// 755. Pour Water
// https://leetcode.com/problems/pour-water/

// Runtime: 8 ms, faster than 27.08% of C++ online submissions for Pour Water.
// Memory Usage: 7.7 MB, less than 16.67% of C++ online submissions for Pour Water.

class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        const int N = heights.size();
        
        auto update = [&](int j) {
            int lh = j > 0 ? heights[j - 1] : INT_MAX;
            int ch = heights[j];
            int rh = j + 1 < N ? heights[j + 1] : INT_MAX;
            int v = min(V, min(lh, rh) - ch);
            v = max(v, 1);
            V -= v;
            heights[j] += v;
        };
        
        auto find = [&](int step) {
            for (int i = K + step, j = K; -1 <= i && i <= N; i += step) {
                if (i == -1 || i == N || heights[i] > heights[j]) {
                    if (j != K) {
                        update(j);
                        return true;
                    }
                    return false;
                } else if (heights[i] == heights[K]) {
                    if (j != K) {
                        update(j);
                        return true;
                    }
                } else if (heights[i] < heights[j]) {
                    j = i;
                }
            }
            return false;
        };
        
        while (V > 0) {
            if (find(-1)) continue;
            if (find(1)) continue;
            update(K);
        }
        return heights;
    }
};