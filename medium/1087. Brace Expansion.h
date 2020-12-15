// 1087. Brace Expansion
// https://leetcode.com/problems/brace-expansion/

// Runtime: 4 ms, faster than 90.95% of C++ online submissions for Brace Expansion.
// Memory Usage: 8.8 MB, less than 40.33% of C++ online submissions for Brace Expansion.
    
class Solution {
public:
    vector<string> expand(string S) {
        vector<string> ans;
        const int N = S.length();
        int i = 0;
        while (i < N) {
            if (S[i] == '{') {
                ++i;
                string t;
                while (S[i] != '}') 
                    if (S[i] == ',') ++i; 
                    else t += S[i++];
                vector<string> tmp;
                if (ans.empty()) 
                    for (char c : t)
                        tmp.emplace_back(1, c); 
                else 
                    for (auto s : ans) 
                        for (char c : t)
                            tmp.push_back(s + c); 
                ans = tmp;
                ++i;
            } else {
                if (ans.empty()) ans.emplace_back(1, S[i]);
                else for (auto& s : ans) s += S[i];
                ++i;
            }
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};