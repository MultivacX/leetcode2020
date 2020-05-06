// 820. Short Encoding of Words

// Runtime: 148 ms, faster than 39.71% of C++ online submissions for Short Encoding of Words.
// Memory Usage: 46.7 MB, less than 100.00% of C++ online submissions for Short Encoding of Words.

// Time Complexity: O(sum(length(word[i]))).
// Space Complexity: O(sum(length(word[i]))).

class Solution {
    struct Trie {
        bool end{false};
        unordered_map<char, Trie*> children;
    };
    
    void build(const string& word, int i, Trie* node) {
        if (i < 0) {
            node->end = true;
            return;
        }
        if (node->children.count(word[i]) == 0)
            node->children[word[i]] = new Trie;
        build(word, i - 1, node->children[word[i]]);
    }
    
    void encode(Trie* node, int cur) {
        if (node->end && node->children.empty()) {
            len += cur + 1/*#*/;
            return;
        }
        
        for (auto c : node->children)
            encode(c.second, cur + 1);
    }
    
    Trie root;
    int len{0};
    
public:
    int minimumLengthEncoding(vector<string>& words) {
        for (const string& word : words)
            build(word, word.length() - 1, &root);
        encode(&root, 0);
        return len;
    }
};