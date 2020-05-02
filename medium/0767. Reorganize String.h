// 767. Reorganize String

// Runtime: 4 ms, faster than 62.20% of C++ online submissions for Reorganize String.
// Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Reorganize String.

// Time Complexity: O(S.length()).
// Space Complexity: O(S.length()).

class Solution {
public:
    string reorganizeString(string S) {
        vector<pair<int, char>> v(26, {0, 0});
        for (const char& c : S) {
            ++v[c - 'a'].first;
            v[c - 'a'].second = c;
        }
        sort(begin(v), end(v), [](pair<int, char>& l, pair<int, char>& r){
            return l.first > r.first;
        });
        
        const int L = v[0].first;
        vector<string> w{string(L, v[0].second)};
        for (int i = 1; i < 26 && v[i].first > 0; ++i) {
            for (int j = 0; j < v[i].first; ++j) {
                if (w.back().length() == L) w.push_back("");
                w.back() += v[i].second;
            }
        }
        
        string ans;
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < w.size() && i < w[j].length(); ++j) {
                if (!ans.empty() && ans.back() == w[j][i]) return "";
                ans += w[j][i];
            }
        }
        return ans;
    }
};