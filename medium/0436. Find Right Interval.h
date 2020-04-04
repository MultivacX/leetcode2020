// 436. Find Right Interval

// Runtime: 152 ms, faster than 28.77% of C++ online submissions for Find Right Interval.
// Memory Usage: 21.5 MB, less than 80.00% of C++ online submissions for Find Right Interval.

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        const int N = intervals.size();
        if (N == 0) return {};
        if (N == 1) return {-1};
        
        vector<vector<int>> t(N, vector<int>(2, 0));
        for (int i = 0; i < N; ++i) {
            t[i][0] = intervals[i][0];
            t[i][1] = i; 
        }
        sort(begin(t), end(t), [](const vector<int>& l, const vector<int>& r){ return l[0] < r[0]; });
        
        vector<int> ans(N, -1);
        for (int i = 0; i < N; ++i) {
            auto it = lower_bound(begin(t), end(t), intervals[i], [](const vector<int>& l, const vector<int>& r){ 
                return l[0] < r[1]; 
            });
            if (it != end(t)) 
                ans[i] = (*it)[1];
        }
        return ans;
    }
};