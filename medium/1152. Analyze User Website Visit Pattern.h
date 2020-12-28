// 1152. Analyze User Website Visit Pattern
// https://leetcode.com/problems/analyze-user-website-visit-pattern/

// Runtime: 136 ms, faster than 9.39% of C++ online submissions for Analyze User Website Visit Pattern.
// Memory Usage: 21 MB, less than 36.40% of C++ online submissions for Analyze User Website Visit Pattern.
    
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        const int N = username.size();
        unordered_map<string, vector<int>> utw;
        for (int i = 0; i < N; ++i) 
            utw[username[i]].push_back(i);
        
        int cnt = 0;
        map<vector<string>, int> m;
        for (auto& it : utw) {
            sort(begin(it.second), end(it.second), [&](int l, int r){
                return timestamp[l] < timestamp[r];
            });
            
            set<vector<string>> s;
            const int M = it.second.size();
            for (int a = 0; a + 2 < M; ++a) {
                const auto& wa = website[it.second[a]];
                for (int b = a + 1; b + 1 < M; ++b) {
                    const auto& wb = website[it.second[b]];
                    for (int c = b + 1; c < M; ++c) {
                        s.insert({wa, wb, website[it.second[c]]});
                    }
                }    
            }
            
            for (auto& v : s) cnt = max(cnt, ++m[v]);
            
            // cout << it.first << ": ";
            // for (int i : it.second) cout << website[i] << " ";
            // cout << endl;
            // if (M >= 3) for (auto& it : m) 
            // printf("    %s %s %s  %d\n", 
            //        it.first[0].c_str(), 
            //        it.first[1].c_str(), 
            //        it.first[2].c_str(), it.second);
            // cout << endl;
        }
        
        for (auto& it : m) 
            if (it.second == cnt)
                return it.first;
        return {};
    }
};