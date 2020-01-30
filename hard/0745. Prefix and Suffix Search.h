// 745. Prefix and Suffix Search

// ["WordFilter","f"]
// [[["apple"]],["app","ple"]]
// [null,-1]

class Trie {
public:
    Trie(char _c = '/0', Trie* p = nullptr, bool e = false) : c(_c), parent(p), end(e) {}
    
    char c;
    Trie* parent;
    bool end;
    Trie* children[26] = {nullptr};
};

class WordFilter {
public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) 
            add(words[i], 0, &head);
    }
    
    int f(string prefix, string suffix) {
        return -1;
    }
    
    void add(const string& word, int wi, Trie* node) {
        if (wi >= word.length()) {
            node->end = true;
            tails[node->c - 'a'].insert(node);
            return;
        }
        
        int i = word[wi] - 'a';
        if (!node->children[i]) 
            node->children[i] = new Trie(word[wi], node);
        add(word, wi + 1, node->children[i]);
    }
    
    Trie head;
    unordered_set<Trie*> tails[26];
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */