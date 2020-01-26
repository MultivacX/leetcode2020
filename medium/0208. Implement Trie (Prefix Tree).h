// 208. Implement Trie (Prefix Tree)

// Runtime: 140 ms, faster than 10.64% of C++ online submissions for Implement Trie (Prefix Tree).
// Memory Usage: 48.1 MB, less than 16.67% of C++ online submissions for Implement Trie (Prefix Tree).

class Trie {
private:
    class Node {
    public:
        Node(char c, bool end = false)
        : content(c)
        , isEnd(end)
        , children(26, nullptr) {
            
        }
        
        char content;
        bool isEnd;
        vector<Node*> children;
    };
    
public:
    /** Initialize your data structure here. */
    Trie() 
    : root(new Node('\0')) {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto node = root;
        for (int i = 0; i < word.length(); ++i) {
            if (!node->children[word[i] - 'a']) {
                node->children[word[i] - 'a'] = new Node(word[i], i == word.length() - 1);
            } else if (i == word.length() - 1) {
                node->children[word[i] - 'a']->isEnd = true;
            }
            node = node->children[word[i] - 'a'];
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto node = root;
        for (int i = 0; i < word.length(); ++i) {
            if (!node->children[word[i] - 'a']) {
                return false;
            } else if (node->children[word[i] - 'a']->isEnd && i == word.length() - 1) {
                return true;
            }
            node = node->children[word[i] - 'a'];
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto node = root;
        for (int i = 0; i < prefix.length(); ++i) {
            if (!node->children[prefix[i] - 'a']) {
                return false;
            }
            node = node->children[prefix[i] - 'a'];
        }
        return true;
    }
    
    Node* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */