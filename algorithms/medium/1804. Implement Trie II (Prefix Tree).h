// 1804. Implement Trie II (Prefix Tree)
// https://leetcode.com/problems/implement-trie-ii-prefix-tree/

// Runtime: 180 ms, faster than 100.00% of C++ online submissions for Implement Trie II (Prefix Tree).
// Memory Usage: 67.3 MB, less than 100.00% of C++ online submissions for Implement Trie II (Prefix Tree).
    
class Trie {
    struct Node {
        int countLetter = 0;
        int countWord = 0;
        vector<Node*> children = vector<Node*>(26, nullptr);
    };
    
    Node root;
    
public:
    Trie() {
        
    }
    
    void insert(string word) {
        const int n = word.length();
        auto* node = &root;
        int i = 0;
        while (i < n) {
            int j = word[i] - 'a';
            if (node->children[j] == nullptr)
                node->children[j] = new Node;
            node = node->children[j];
            
            ++(node->countLetter);
            if (++i == n)
                ++(node->countWord);
        }
    }
    
    int countWordsEqualTo(string word) {
        const int n = word.length();
        auto* node = &root;
        int i = 0;
        while (i < n) {
            int j = word[i] - 'a';
            if (node->children[j] == nullptr)
                return 0;
            node = node->children[j];
            
            if (node->countLetter == 0)
                return 0;
            
            if (++i == n)
                return node->countWord;
        }
        return 0;
    }
    
    int countWordsStartingWith(string prefix) {
        const int n = prefix.length();
        auto* node = &root;
        int i = 0;
        while (i < n) {
            int j = prefix[i] - 'a';
            if (node->children[j] == nullptr)
                return 0;
            node = node->children[j];
            
            if (node->countLetter == 0)
                return 0;
            
            if (++i == n)
                return node->countLetter;
        }
        return 0;
    }
    
    void erase(string word) {
        const int n = word.length();
        auto* node = &root;
        int i = 0;
        while (i < n) {
            int j = word[i] - 'a';
            node = node->children[j];
            
            --(node->countLetter);
            if (++i == n)
                --(node->countWord);
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */


// WA
class Trie {
    struct Node {
        Node(char letter_ = '\0') 
        : letter(letter_), is_end(false), count(0), children(26, nullptr) {}
        
        char letter;
        bool is_end;
        int count;
        vector<Node*> children;
    };
    
    Node root;
    
    void insert(const string& word, int i, Node* node) {
        if (i >= word.length()) {
            node->is_end = true;
            return;
        }
        
        int j = word[i] - 'a';
        if (node->children[j] == nullptr) 
            node->children[j] = new Node(word[i]);
        ++node->children[j]->count;
        insert(word, i + 1, node->children[j]);
    }
    
    int count(const string& word, int i, Node* node, bool is_end) {
        if (i >= word.length()) {
            if (is_end) 
                return node->is_end ? node->count : 0;
            return node->count;
        }
        
        int j = word[i] - 'a';
        if (node->children[j] == nullptr) return 0;
        if (node->children[j]->count == 0) return 0;
        return count(word, i + 1, node->children[j], is_end);
    }
    
    bool find(const string& word, int i, Node* node, vector<Node*>& nodes) {
        nodes.push_back(node);
        if (i >= word.length()) return node->is_end;
        
        int j = word[i] - 'a';
        if (node->children[j] == nullptr) return false;
        if (node->children[j]->count == 0) return false;
        return find(word, i + 1, node->children[j], nodes);
    }
    
    void erase(const string& word, int i, Node* node) {
        vector<Node*> nodes;
        if (!find(word, 0, &root, nodes)) return;
        
        for (int i = 1; i < nodes.size(); ++i) {
            auto parent = nodes[i - 1];
            auto node = nodes[i];
            if (--node->count == 0) {
                int j = node->letter - 'a';
                parent->children[j] = nullptr;
                delete node;
                return;
            }
        }
    }
    
public:
    Trie() {
        
    }
    
    void insert(string word) {
        insert(word, 0, &root);
    }
    
    int countWordsEqualTo(string word) {
        return count(word, 0, &root, true);
    }
    
    int countWordsStartingWith(string prefix) {
        return count(prefix, 0, &root, false);
    }
    
    void erase(string word) {
        erase(word, 0, &root);
    }
};