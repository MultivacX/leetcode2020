// 211. Add and Search Word - Data structure design

// Runtime: 88 ms, faster than 90.54% of C++ online submissions for Add and Search Word - Data structure design.
// Memory Usage: 44.7 MB, less than 81.82% of C++ online submissions for Add and Search Word - Data structure design.

class WordDictionary {
    struct Word {
        Word(char c_, bool e_ = false) : c(c_), end(e_) {}
        char c;
        bool end;
        array<Word*, 26> children{nullptr};
    };
    
    Word* root;
    
public:
    /** Initialize your data structure here. */
    WordDictionary() : root(new Word('\0')) {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        if (word.empty()) 
            return;
        
        auto node = root;
        for (auto c : word) {
            if (!node->children[c - 'a'])
                node->children[c - 'a'] = new Word(c);
            node = node->children[c - 'a'];
        }
        node->end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, 0, root);
    }
    
    bool search(const string& word, int idx, Word* parent) {
        if (word.length() <= idx) 
            return parent && parent->end;
        
        if (word[idx] == '.') {
            for (int i = 0; i < 26; ++i) {
                if (!parent->children[i])
                    continue;
                if (search(word, idx + 1, parent->children[i]))
                    return true;
            }
        } else if (parent->children[word[idx] - 'a']) {
            return search(word, idx + 1, parent->children[word[idx] - 'a']);
        }
        
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */