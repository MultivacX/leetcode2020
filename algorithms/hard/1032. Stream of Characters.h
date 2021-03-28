// 1032. Stream of Characters
// https://leetcode.com/problems/stream-of-characters/

// Runtime: 224 ms, faster than 69.86% of C++ online submissions for Stream of Characters.
// Memory Usage: 103.4 MB, less than 90.07% of C++ online submissions for Stream of Characters.
    
class StreamChecker {
    class Trie {
    public:
        Trie() {}
        Trie* children[26] = {nullptr};
        bool is_first = false;
    };
    
    void build(const string& s, int idx, Trie* node) {
        int i = s[idx] - 'a';
        if (!node->children[i]) node->children[i] = new Trie();
        node = node->children[i];
        
        if (idx > 0) build(s, idx - 1, node);
        else node->is_first = true;
    }
    
    bool query(int idx, Trie* node, int l) {
        if (idx < 0) return false;
        if (l > maxLength[stream.back() - 'a']) return false;
        
        int i = stream[idx] - 'a';
        if (!node->children[i]) return false;
        node = node->children[i];
        
        if (node->is_first) return true;
        return query(idx - 1, node, l + 1);
    }
    
    Trie root;
    string stream;
    int maxLength[26] = {0};
    
public:
    StreamChecker(vector<string>& words) {
        for (const auto& w : words) {
            if (w.empty()) continue;
            build(w, w.length() - 1, &root);
            maxLength[w.back() - 'a'] = max(maxLength[w.back() - 'a'], (int)w.length());
        }
            
    }
    
    bool query(char letter) {
        stream.push_back(letter);
        return query(stream.length() - 1, &root, 1);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */