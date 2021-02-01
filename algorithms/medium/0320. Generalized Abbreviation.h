// 320. Generalized Abbreviation
// https://leetcode.com/problems/generalized-abbreviation/

// Runtime: 104 ms, faster than 12.77% of C++ online submissions for Generalized Abbreviation.
// Memory Usage: 36 MB, less than 6.38% of C++ online submissions for Generalized Abbreviation.
    
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> bfs;
        for (int i = 0; i < word.length(); ++i) {
            if (i == 0) {
                string a; a.push_back(1);
                string b; b.push_back(word[i]);
                bfs.push_back(a);
                bfs.push_back(b);
                continue;
            }
            
            vector<string> tmp;
            for (auto str : bfs) {
                if (str.back() <= 20) {
                    tmp.push_back(str); ++tmp.back().back();
                } else {
                    tmp.push_back(str); tmp.back().push_back(1);
                }
                tmp.push_back(str); tmp.back().push_back(word[i]);
            }
            bfs = tmp;
        }
        
        vector<string> ans;
        for (auto& str : bfs) {
            string w;
            for (char c : str) {
                if (c <= 20) w += to_string((int)c);
                else w.push_back(c);
            }
            ans.push_back(w);
        }
        return ans;
    }
};