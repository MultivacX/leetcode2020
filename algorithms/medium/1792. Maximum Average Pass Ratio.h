// 1792. Maximum Average Pass Ratio
// https://leetcode.com/problems/maximum-average-pass-ratio/

// Runtime: 1168 ms, faster than 100.00% of C++ online submissions for Maximum Average Pass Ratio.
// Memory Usage: 84.2 MB, less than 100.00% of C++ online submissions for Maximum Average Pass Ratio.
    
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto ratio = [](double pass, double total) {
            return pass / total;
        };
        auto delta = [&ratio](double pass, double total){
            return ratio(pass + 1, total + 1) - ratio(pass, total);
        };
        auto cmp = [&](int l, int r){
            return delta(classes[l][0], classes[l][1]) < delta(classes[r][0], classes[r][1]);
        };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        
        const int n = classes.size();
        for (int i = 0; i < n; ++i)
            if (classes[i][0] != classes[i][1])
                q.push(i);
        while (!q.empty() && extraStudents-- > 0) {
            int i = q.top();
            q.pop();
            ++classes[i][0];
            ++classes[i][1];
            q.push(i);
        }
        
        // for (const auto& c : classes) cout << c[0] << "," << c[1] << " ";
        
        double ans = 0;
        for (const auto& c : classes)
            ans += ratio(c[0], c[1]);
        return ans / n;
    }
};