// 1858. Longest Word With All Prefixes
// https://leetcode.com/problems/longest-word-with-all-prefixes/

// Runtime: 184 ms, faster than 100.00% of C++ online submissions for Longest Word With All Prefixes.
// Memory Usage: 154.4 MB, less than 100.00% of C++ online submissions for Longest Word With All Prefixes.
    
class Solution {
    struct Trie {
        int k = 0;
        vector<Trie*> children = vector<Trie*>(26);
    };
    
    void add(const string& word, int i, Trie* node) {
        if (i >= word.length()) {
            node->k = 1;
            return;
        }
        
        int j = word[i] - 'a';
        if (!node->children[j])
            node->children[j] = new Trie;
        add(word, i + 1, node->children[j]);
    }
    
    void count(Trie* node, int& cur_k, string& cur, int& word_k, string& word) {
        for (int i = 0; i < 26; ++i) {
            auto child = node->children[i];
            if (!child || !child->k) continue;
            
            cur_k += child->k;
            cur.push_back('a' + i);
            
            if (cur.length() > word.length())
                word = cur;
            
            count(child, cur_k, cur, word_k, word);
            
            cur_k -= child->k;
            cur.pop_back();
        }
    }
    
    Trie root;
    
public:
    string longestWord(vector<string>& words) {
        for (const string& word : words)
            add(word, 0, &root);
        
        int cur_k = 0;
        string cur;
        int word_k = 0;
        string word;
        count(&root, cur_k, cur, word_k, word);
        return word;
    }
};