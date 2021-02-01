// 1642. Furthest Building You Can Reach
// https://leetcode.com/problems/furthest-building-you-can-reach/

// Runtime: 276 ms, faster than 34.97% of C++ online submissions for Furthest Building You Can Reach.
// Memory Usage: 55.4 MB, less than 27.25% of C++ online submissions for Furthest Building You Can Reach.
    
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        const int N = heights.size();
        int ans = 0;
        priority_queue<int64_t, vector<int64_t>, greater<int64_t>> q;
        int64_t D = 0, L = 0;
        for (int i = 1; i < N; ++i) {
            if (heights[i - 1] >= heights[i]) {
                ans = i;
                continue;
            }
            
            int64_t d = heights[i] - heights[i - 1];
            D += d;
            L += d;
            q.push(d);
            while (q.size() > ladders) {
                L -= q.top(); q.pop();
            }
            int64_t B = D - L;
            if (B <= bricks && q.size() <= ladders) ans = i;
            else break;
        }
        return ans;
    }
};

// TLE
/*class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        const int N = heights.size();
        int ans = 0;
        unordered_set<int64_t> s{ladders + (int64_t)bricks * (N + 1)};
        unordered_set<int64_t> t;
        for (int i = 1; i < N && !s.empty(); ++i) {
            if (heights[i - 1] >= heights[i]) {
                ans = i;
                continue;
            }
            
            int diff = heights[i] - heights[i - 1];
            t.clear();
            for (auto v : s) {
                auto l = v % (N + 1);
                auto b = v / (N + 1);
                if (l > 0) t.insert(l - 1 + (int64_t)b * (N + 1));
                if (b >= diff) t.insert(l + (int64_t)(b -diff) * (N + 1));
            }
            if (!t.empty()) ans = i;
            s = t;
        }
        return ans;
    }
};*/