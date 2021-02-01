// 290. Word Pattern

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Word Pattern.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Word Pattern.

// Time Complexity: O(pattern.length()).
// Space Complexity: O(pattern.length()).

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m;
        unordered_map<string, char> n;
        int i = 0;
        istringstream words(str);
        string word;
        while (getline(words, word, ' ')) {
            // key : pattern[i]
            // val : word
            if (i >= pattern.length()) return false;
            
            auto it_m = m.find(pattern[i]);
            auto it_n = n.find(word);
            
            if (it_m != m.end() || it_n != n.end()) {
                if (it_m == m.end() || it_n == n.end()) return false;
                if (it_m != m.end() && it_m->second != word) return false;
                if (it_n != n.end() && it_n->second != pattern[i]) return false;
            } else {
                m[pattern[i]] = word;
                n[word] = pattern[i];
            }
            // cout << pattern[i] << " : " << word << endl;
            ++i;
        }
        return i == pattern.length();
    }
};