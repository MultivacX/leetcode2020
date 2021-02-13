// 42. Trapping Rain Water

// Runtime: 8 ms, faster than 59.43% of C++ online submissions for Trapping Rain Water.
// Memory Usage: 9.5 MB, less than 7.60% of C++ online submissions for Trapping Rain Water.

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;
        
        auto cmp = [&](int i, int j) { return height[i] < height[j] || (height[i] == height[j] && i < j); };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        for (int i = 0; i < n; ++i) q.push(i);
        
        int ans = 0;
        int lmax = height[0];
        for (int i = 1; i < n - 1; ++i) {
            if (lmax <= height[i]) {
                lmax = height[i];
                continue;
            } 
            
            while (!q.empty() && q.top() <= i) q.pop();
            if (q.empty()) break;
            int rmax = height[q.top()];
            if (rmax > height[i]) ans += min(lmax, rmax) - height[i];
        }
        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        if (n <= 2) return 0;
        
        int ans = 0;
        vector<int> left;
        for (int i = 0, h = INT_MIN; i < n; ++i) {
            left.push_back(h);
            h = max(h, height[i]);
        }
        for (int i = n - 2, r = height[n - 1]; i > 0; --i) {
            int l = left[i];
            int m = height[i];
            if (l > m && m < r)
                ans += min(l, r) - m;
            r = max(r, m);
        }
        return ans;
    }
};