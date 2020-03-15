// 720. Longest Word in Dictionary

// Runtime: 52 ms, faster than 78.50% of C++ online submissions for Longest Word in Dictionary.
// Memory Usage: 15.4 MB, less than 100.00% of C++ online submissions for Longest Word in Dictionary.

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(begin(words), end(words), [](string& l, string& r){
            return l.length() > r.length() || (l.length() == r.length() && l < r);
        });
        // for (auto& w : words) cout << w << ", ";
        if (words.back().length() > 1) return "";
        
        unordered_set<string> s(begin(words), end(words));
        for (auto& w : words) {
            int l = 1;
            while (l < w.length() && s.count(w.substr(0, l))) 
                ++l;
            if (l == w.length())
                return w;
        }
        return "";
    }
};