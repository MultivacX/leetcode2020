// 1181. Before and After Puzzle
// https://leetcode.com/problems/before-and-after-puzzle/

// Runtime: 12 ms, faster than 89.47% of C++ online submissions for Before and After Puzzle.
// Memory Usage: 10.5 MB, less than 84.21% of C++ online submissions for Before and After Puzzle.
    
class Solution {
    string first(const string& s) {
        string t;
        for (char c : s) {
            if (c == ' ') break;
            t += c;
        }
        return t;
    }
    
    string last(const string& s) {
        string t;
        for (int i = s.length() - 1; i >= 0 && s[i] != ' '; --i)
            t += s[i];
        reverse(begin(t), end(t));
        return t;
    }
    
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        // sort(begin(phrases), end(phrases));
        unordered_map<string, vector<int>> first_words;
        for (int i = 0; i < phrases.size(); ++i) 
            first_words[first(phrases[i])].push_back(i);
        
        set<string> ans;
        for (int i = 0; i < phrases.size(); ++i)  {
            auto key = last(phrases[i]);
            auto it = first_words.find(key);
            if (it == first_words.end()) continue;
            for (int j : it->second) {
                if (i == j) continue;
                if (phrases[i] == phrases[j]) ans.insert(phrases[i]);
                else ans.insert(phrases[i] + phrases[j].substr(it->first.length()));   
            }
        }
        return vector<string>(begin(ans), end(ans));
    }
};