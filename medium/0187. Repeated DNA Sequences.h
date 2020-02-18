// 187. Repeated DNA Sequences

// Runtime: 52 ms, faster than 60.62% of C++ online submissions for Repeated DNA Sequences.
// Memory Usage: 24.5 MB, less than 45.45% of C++ online submissions for Repeated DNA Sequences.

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, pair<int, int>> m;
        for (int i = 0; i < (int)s.length() - 9; ++i) {
            string ss(s.substr(i, 10));
            auto it = m.find(ss);
            if (it == m.end()) {
                m.insert({ss, {i, i}});
            } else if (m[ss].first == m[ss].second) {
                m[ss].second = i;
                ans.push_back(ss);
            }
        }
        return ans;
    }
};