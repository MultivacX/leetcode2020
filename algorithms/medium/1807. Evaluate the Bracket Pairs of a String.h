// 1807. Evaluate the Bracket Pairs of a String
// https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/

// Runtime: 324 ms, faster than 94.52% of C++ online submissions for Evaluate the Bracket Pairs of a String.
// Memory Usage: 113.8 MB, less than 98.97% of C++ online submissions for Evaluate the Bracket Pairs of a String.

    
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, int> m;
        for (int i = 0; i < knowledge.size(); ++i)
            m.emplace(knowledge[i][0], i);
        
        string t, k;
        int i = 0;
        while (i < s.length()) {
            if (s[i] == '(') {
                ++i;
                k += s[i++];
            } else if (s[i] == ')') {
                ++i;
                
                auto it = m.find(k);
                if (it == end(m)) {
                    t += '?';
                } else {
                    t += knowledge[it->second][1];    
                }
                k = "";
            } else if (!k.empty()) {
                k += s[i++];
            } else {
                t += s[i++];
            }
        }
        return t;
    }
};