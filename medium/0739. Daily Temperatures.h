// 739. Daily Temperatures

// Runtime: 184 ms, faster than 95.98% of C++ online submissions for Daily Temperatures.
// Memory Usage: 15.5 MB, less than 68.00% of C++ online submissions for Daily Temperatures.

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        const int n = T.size();
        if (n == 0) return {};
        if (n == 1) return {0};
        
        vector<int> ans(n, 0);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && T[s.top()] < T[i]) {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};