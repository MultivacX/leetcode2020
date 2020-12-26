// 358. Rearrange String k Distance Apart
// https://leetcode.com/problems/rearrange-string-k-distance-apart/

// Runtime: 8 ms, faster than 99.24% of C++ online submissions for Rearrange String k Distance Apart.
// Memory Usage: 9.7 MB, less than 70.08% of C++ online submissions for Rearrange String k Distance Apart.
    
class Solution {
public:
    string rearrangeString(string s, int k) {
        vector<pair<int, char>> v(26);
        for (char c : s) {
            ++v[c - 'a'].first;
            v[c - 'a'].second = c;
        }
        sort(begin(v), end(v));
        const int N = v[25].first;
        vector<string> strs(N, string(1, v[25].second));
        for (int i = 24, j = 0; i >= 0 && v[i].first > 0; --i) {
            const int M = v[i].first == N ? N : N - 1;
            char c = v[i].second;
            for (int k = 0; k < v[i].first; ++k) {
                if (j >= M) j = 0;
                strs[j++] += c;
            }
        }
        string t;
        for (auto& str : strs) t += str;
        // cout << t << endl;
        vector<int> p(26, -k);
        for (int i = 0; i < t.length(); ++i) {
            if (i - p[t[i] - 'a'] < k)
                return "";
            p[t[i] - 'a'] = i;
        }
        return t;
    }
};