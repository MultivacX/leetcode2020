// 1096. Brace Expansion II
// https://leetcode.com/problems/brace-expansion-ii/

// Runtime: 28 ms, faster than 13.94% of C++ online submissions for Brace Expansion II.
// Memory Usage: 11.2 MB, less than 80.61% of C++ online submissions for Brace Expansion II.
    
class Solution {
    string readWord(const string& e, int& i) {
        const int n = e.length();
        string w;
        while (i < n && 'a' <= e[i] && e[i] <= 'z')
            w += e[i++];
        return w;
    }
    
    unordered_set<string> expanse(const string& e, int& i) {
        const int n = e.length();
        unordered_set<string> ans;
        
        unordered_set<string> s;
        while (i < n && e[i] != '}') {
            if (e[i] == ',') {
                ans.insert(begin(s), end(s));
                s.clear();
                ++i;
            }
            
            unordered_set<string> t;
            if (e[i] == '{') {
                t = expanse(e, ++i);  
                ++i;
            } else {
                t.insert(readWord(e, i));
            }
            
            if (s.empty()) {
                swap(s, t);
            } else {
                unordered_set<string> r;
                for (const auto& a : s)
                    for (const auto& b : t)
                        r.insert(a + b);
                swap(s, r);
            }
        }
        
        ans.insert(begin(s), end(s));
        return ans;
    }
    
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        auto s = expanse(expression, i);  
        vector<string> ans;
        for (const auto& a : s)
            ans.push_back(a);
        sort(begin(ans), end(ans));
        return ans;
    }
};