// 1686. Stone Game VI
// https://leetcode.com/problems/stone-game-vi/

// Runtime: 520 ms, faster than 79.78% of C++ online submissions for Stone Game VI.
// Memory Usage: 107.9 MB, less than 80.95% of C++ online submissions for Stone Game VI.
    
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        const int N = aliceValues.size();
        vector<pair<int, int>> vals(N);
        for (int i = 0; i < N; ++i) {
            vals[i].first = aliceValues[i];
            vals[i].second = bobValues[i];
        }
        sort(begin(vals), end(vals), [](pair<int, int>& l, pair<int, int>& r){
            int d1 = l.first + l.second;
            int d2 = r.first + r.second;
            return d1 < d2 || (d1 == d2 && l.first < r.first);
        });
        int a = 0, b = 0;
        for (int i = N - 1, k = 0; i >= 0; --i, ++k) {
            if ((k & 1) == 0) a += vals[i].first;
            else b += vals[i].second;
        }
        if (a == b) return 0;
        return a > b ? 1 : -1;
    }
};