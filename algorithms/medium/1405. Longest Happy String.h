// 1405. Longest Happy String

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Happy String.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Longest Happy String.

// Time Complexity: O(a+b+c).
// Space Complexity: O(a+b+c).

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        if (a + b + c == 0) return "";
        vector<pair<int, char>> v{{a, 'a'}, {b, 'b'}, {c, 'c'}};
        sort(rbegin(v), rend(v));
        while (v.back().first == 0) v.pop_back();
        
        vector<string> strs;
        for (int i = 0; i < v[0].first; i += 2) {
            if (i + 1 < v[0].first) strs.emplace_back(2, v[0].second);
            else strs.emplace_back(1, v[0].second);
        }
        for (int j = 1, row = 0; j < v.size(); ++j) {
            for (int i = 0; i < v[j].first; ++i) {
                strs[row] += v[j].second;
                ++row;
                if (row >= strs.size()) row = 0;
            }   
        }
        // for (auto& s : strs) cout << s << endl;
        string ans;
        for (auto& s : strs) {
            const int l = ans.length();
            if (l >= 2 && ans[l - 2] == ans[l - 1] && ans[l - 1] == s[0]) break;
            ans += s;
        }
        return ans;
    }
};