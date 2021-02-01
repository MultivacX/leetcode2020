// 676. Implement Magic Dictionary

// Runtime: 4 ms, faster than 69.92% of C++ online submissions for Implement Magic Dictionary.
// Memory Usage: 7.4 MB, less than 100.00% of C++ online submissions for Implement Magic Dictionary.

class MagicDictionary {
public:    
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (const auto& word : dict) {
            auto w = word;
            for (int i = 0; i < word.length(); ++i) {
                char t = w[i];
                w[i] = '*';
                m[w].insert(word);
                w[i] = t;
            }
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        // cout << word << ": ";
        auto w = word;
        for (int i = 0; i < word.length(); ++i) {
            char t = w[i];
            w[i] = '*';
            // cout << w << ", ";
            auto it = m.find(w);
            if (it != m.end()) {
                const unordered_set<string>& words = it->second;
                if (words.count(word) == 0) return true;
                if (words.size() > 1) return true;
            }
            w[i] = t;
        }
        // cout << endl;
        return false;
    }
    
    unordered_map<string, unordered_set<string>> m;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */