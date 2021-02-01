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

// Runtime: 96 ms
// Memory Usage: 23.8 MB
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int N = s.length();
        if (N < 10) return {};
        
        static unordered_map<char, uint64_t> M{{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
        
        uint64_t h = 0;
        uint64_t p = 1;
        for (int i = 0; i < 10; ++i) {
            h += p * M[s[i]];
            p *= 10;
        }
        p = 1000000000;
        
        unordered_map<uint64_t, pair<string, int>> m;
        m.emplace(h, pair<string, int>{s.substr(0, 10), 1});
        // cout << h << " " << s.substr(0, 10) << endl;
        for (int i = 10; i < N; ++i) {
            h /= 10;
            // cout << h << endl;
            h += p * M[s[i]];
            // cout << h << " " << p << "*" << M[s[i]] << endl;
            if (m.count(h) == 0)
                m.emplace(h, pair<string, int>{s.substr(i - 9, 10), 1});
            else 
                ++m[h].second;
            // cout << h << " " << s.substr(i - 9, 10) << endl;
        }
        
        vector<string> ans;
        for (auto it : m) if (it.second.second > 1) ans.push_back(it.second.first);
        return ans;
    }
};