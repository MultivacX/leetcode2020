// 84. Largest Rectangle in Histogram

// Runtime: 24 ms, faster than 26.76% of C++ online submissions for Largest Rectangle in Histogram.
// Memory Usage: 14.1 MB, less than 5.72% of C++ online submissions for Largest Rectangle in Histogram.

// Time Complexity: O(N).
// Space Complexity: O(N).

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int N = heights.size();
        if (N == 0) return 0;
        
        int ans = heights[0];
        // {idx, left_idx : heights[left_idx] >= heights[idx] }
        stack<pair<int, int>> s;
        s.push({0, 0});
        for (int i = 1; i < N; ++i) {
            int left = i;
            while (!s.empty() && heights[s.top().first] >= heights[i]) {
                int area = (i - s.top().second) * heights[s.top().first];
                left = s.top().second;
                ans = max(ans, area);
                s.pop();
            }
            
            if (s.empty() || heights[s.top().first] < heights[i]) 
                s.push({i, left});
        }
        
        int j = -1;
        while (!s.empty()) {
            if (j < 0) j = s.top().first + 1;
            int area = (j - s.top().second) * heights[s.top().first];
            ans = max(ans, area);
            s.pop();
        }
        
        return ans;
    }
};


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();
        // stk[x, y]: x < y, heights[x] < heights[y], heights[x+1 ... y-1] >= heights[y]
        stack<int> stk; stk.push(-1);
        int ans = 0;
        
        auto updateArea = [&](const int right_bound){
            int j = stk.top(); stk.pop();
            int area = heights[j] * (right_bound - stk.top() - 1);
            ans = max(ans, area);
        };
        
        for (int i = 0; i < n; ++i) {
            while (stk.top() != -1 && heights[stk.top()] >= heights[i]) 
                updateArea(i);
            stk.push(i);
        }
        while (stk.top() != -1) 
            updateArea(n);
        
        return ans;
    }
};