// 1772. Sort Features by Popularity
// https://leetcode.com/problems/sort-features-by-popularity/

// Runtime: 632 ms, faster than 100.00% of C++ online submissions for Sort Features by Popularity.
// Memory Usage: 75.5 MB, less than 100.00% of C++ online submissions for Sort Features by Popularity.
    
class Solution {
public:
    vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {
        // feature: {-appearances, idx}
        unordered_map<string, vector<int>> m;
        for (int i = 0; i < features.size(); ++i)
            m.insert({features[i], vector<int>{0, i}});
        
        for (int i = 0, j = 0; i < responses.size(); ++i) {
            unordered_set<string> visited;
            istringstream s(responses[i]);
            while (!s.eof()) {
                string r; s >> r;
                if (!visited.insert(r).second) continue;
                auto it = m.find(r);
                if (it == m.end()) continue;
                --it->second[0];
            }
        }
        
        sort(begin(features), end(features), [&m](const string& l, const string& r){
            return m[l][0] < m[r][0] || (m[l][0] == m[r][0] && m[l][1] < m[r][1]);
        });
        return features;
    }
};