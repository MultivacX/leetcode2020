// 1048. Longest String Chain

// Runtime: 148 ms, faster than 64.48% of C++ online submissions for Longest String Chain.
// Memory Usage: 16.5 MB, less than 100.00% of C++ online submissions for Longest String Chain.

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(begin(words), end(words), [](const string& l, const string& r){
            return l.length() < r.length();
        });
        
        int ans = 0;
        unordered_map<string, int> m{{"", 0}};
        for (const string& w : words) {
            m[w] = 1;
            for (int i = 0; i < w.length(); ++i) {
                string t(w.substr(0, i) + w.substr(i + 1));
                auto it = m.find(t);
                if (it == m.end()) continue;
                m[w] = max(m[w], it->second + 1);
            }
            ans = max(ans, m[w]);
        }
        return ans;
    }
};