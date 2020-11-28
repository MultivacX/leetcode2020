// 288. Unique Word Abbreviation
// https://leetcode.com/problems/unique-word-abbreviation/

// Runtime: 200 ms, faster than 52.31% of C++ online submissions for Unique Word Abbreviation.
// Memory Usage: 42.4 MB, less than 96.92% of C++ online submissions for Unique Word Abbreviation.
    
class ValidWordAbbr {
    unordered_map<string, string> m;
    
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (const auto& s : dictionary) {
            string key(s.front() + to_string(s.length() - 2) + s.back());
            auto it = m.find(key);
            if (it == m.end()) m.insert({key, s});
            else if (it->second == s) continue;
            else if (!it->second.empty()) it->second.clear();
        }
    }
    
    bool isUnique(string s) {
        string key(s.front() + to_string(s.length() - 2) + s.back());
        auto it = m.find(key);
        return it == m.end() || it->second == s;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */