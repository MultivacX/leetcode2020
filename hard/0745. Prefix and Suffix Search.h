// 745. Prefix and Suffix Search

// Runtime: 680 ms, faster than 32.84% of C++ online submissions for Prefix and Suffix Search.
// Memory Usage: 262.1 MB, less than 33.33% of C++ online submissions for Prefix and Suffix Search.

class Trie {
public:
    Trie(int w = -1) 
    : children(27, nullptr)
    , weight(w) {
        
    }
    
    vector<Trie*> children;
    int weight;
};

class WordFilter {
public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            // cout << words[i] << ":" << endl << "  ";
            const int n = words[i].length();
            // ascii : behind z is {
            for (int l = 0; l <= n; ++l) {
                string prefix(words[i].substr(0, l));
                for (int j = 0; j <= n; ++j) {
                    string suffix(words[i].substr(j));
                    string word(prefix + "{" + suffix);
                    // cout << word << ", ";
                    build(&root, 0, word, i);
                }
            }
            // cout << endl;
        }
    }
    
    int f(string prefix, string suffix) {
        string word(prefix + "{" + suffix);
        return find(&root, 0, word);
    }
    
    Trie root;
    
    void build(Trie* node, int idx, const string& word, int weight) {
        const int n = word.length();
        if (idx >= n) {
            node->weight = max(node->weight, weight);
            return;
        }
        
        if (node->children[word[idx] - 'a'] == nullptr)
            node->children[word[idx] - 'a'] = new Trie();
        build(node->children[word[idx] - 'a'], idx + 1, word, weight);
    }
    
    int find(Trie* node, int idx, const string& word) {
        const int n = word.length();
        if (idx >= n) 
            return node->weight;
        
        if (node->children[word[idx] - 'a'] == nullptr)
            return -1;
        return find(node->children[word[idx] - 'a'], idx + 1, word);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */