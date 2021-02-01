// 472. Concatenated Words
// https://leetcode.com/problems/concatenated-words/

// Runtime: 364 ms, faster than 86.85% of C++ online submissions for Concatenated Words.
// Memory Usage: 260.1 MB, less than 16.67% of C++ online submissions for Concatenated Words.

class Solution {
    struct Trie {
        Trie() : is_end(false), children(26, nullptr) {}
        
        bool is_end;
        vector<Trie*> children;
    };
    
    Trie root;
    
    void build(const string& word, int i, Trie* node) {
        if (i >= word.length()) {
            node->is_end = true;
            return;
        }
        
        int j = word[i] - 'a';
        if (!node->children[j]) node->children[j] = new Trie;
        build(word, i + 1, node->children[j]);
    }
    
    int count_comprised_words(const string& word, int i, Trie* node) {
        int j = word[i] - 'a';
        auto child = node->children[j];
        if (!child) return 0;
        
        if (child->is_end) {
            if (i + 1 == word.length()) return 1;
            int cnt = count_comprised_words(word, i + 1, &root);
            if (cnt > 0) return cnt + 1;
        } 
        
        if (i + 1 == word.length()) return 0;
        return count_comprised_words(word, i + 1, child);
    }
    
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        
        // bool has_empty_word = false;
        // for (const auto& word : words) {
        //     if (word.empty()) {
        //         has_empty_word = true;
        //         break;
        //     }
        // }
        // if (has_empty_word) {
        //     for (const auto& word : words) 
        //         if (!word.empty()) 
        //             ans.push_back(word);
        //     return ans;
        // }
        
        for (const auto& word : words) 
            if (!word.empty()) build(word, 0, &root);
        for (const auto& word : words) 
            if (!word.empty() && count_comprised_words(word, 0, &root) > 1) 
                ans.push_back(word);
        return ans;
    }
};