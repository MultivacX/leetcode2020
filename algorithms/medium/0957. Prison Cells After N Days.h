// 957. Prison Cells After N Days
// https://leetcode.com/problems/prison-cells-after-n-days/

// Runtime: 16 ms, faster than 28.19% of C++ online submissions for Prison Cells After N Days.
// Memory Usage: 12.5 MB, less than 39.05% of C++ online submissions for Prison Cells After N Days.

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        string cur;
        for (int i : cells) cur.push_back('0' + i);
        string next(cur);
        
        int n = 0;
        unordered_map<string, int> m{{cur, n}};
        while (n < N) {
            next[0] = '0';
            next[7] = '0';
            for (int i = 1; i < 7; ++i)
                next[i] = cur[i - 1] == cur[i + 1] ? '1' : '0';
            swap(cur, next);
            ++n;
            // cout << cur << endl;
            
            if (m.count(cur)) {
                int dist = n - m[cur];
                n += (N - n) / dist * dist;
            }
            m[cur] = n;
        }
        
        vector<int> ans;
        for (char i : cur) ans.push_back(i - '0');
        return ans;
    }
};