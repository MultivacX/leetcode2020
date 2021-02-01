// 291. Word Pattern II
// https://leetcode.com/problems/word-pattern-ii/

// Runtime: 8 ms, faster than 97.19% of C++ online submissions for Word Pattern II.
// Memory Usage: 7.7 MB, less than 94.78% of C++ online submissions for Word Pattern II.
    
class Solution {
    unordered_map<char, string> p2s;
    unordered_map<string, char> s2p;
    int PL;
    int SL;
    
    bool dfs(const string& pattern, const string& s, int i, int j) {
        if (i >= PL || j >= SL) return i >= PL && j >= SL;
        
        const int L = (SL - j) - (PL - i - 1);
        auto it_p2s = p2s.find(pattern[i]);
        if (it_p2s != p2s.end()) {
            int l = it_p2s->second.length();
            return l <= L &&
                   it_p2s->second == s.substr(j, l) &&
                   dfs(pattern, s, i + 1, j + l);
        }
        
        for (int l = 1; l <= L; ++l) {
            string str(s.substr(j, l));
            auto it_s2p = s2p.find(str);
            if (it_s2p != s2p.end()) continue;
            
            p2s.insert({pattern[i], str});
            s2p.insert({str, pattern[i]});
            if (dfs(pattern, s, i + 1, j + l)) return true;
            p2s.erase(pattern[i]);
            s2p.erase(str);
        }
        
        return false;
    }
    
public:
    bool wordPatternMatch(string pattern, string s) {
        PL = pattern.length();
        SL = s.length();
        return PL <= SL && dfs(pattern, s, 0, 0);
    }
};