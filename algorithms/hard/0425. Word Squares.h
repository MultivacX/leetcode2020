// 425. Word Squares
// https://leetcode.com/problems/word-squares/

// Runtime: 72 ms, faster than 86.27% of C++ online submissions for Word Squares.
// Memory Usage: 16.3 MB, less than 85.97% of C++ online submissions for Word Squares.
    
class Solution {
    class Trie {
    public:
        Trie(int i = -1) : idx(i) {}
        int idx;
        Trie* children[26] = {nullptr};
    };
    
    void buildTrie(const string& s, int idx, Trie* root) {
        if (idx == s.length()) return;

        int i = s[idx] - 'a';
        if (!root->children[i]) 
            root->children[i] = new Trie(i);
        buildTrie(s, idx + 1, root->children[i]);
    }
    
    vector<vector<string>> ans;
    Trie root;
    int n;
    vector<string> square;
    
    Trie* getTrieNode(const string& w, int idx, Trie* root) {
        if (idx == w.length()) return root;
        
        int i = w[idx] - 'a';
        if (root->children[i]) 
            return getTrieNode(w, idx + 1, root->children[i]);
        return nullptr;
    }

    void helper(const vector<string>& words, string& w, Trie* node) {
        if (w.length() == n) {
            square.push_back(w);
            helper(words);
            square.pop_back();
            return;
        }
        
        if (!node) return;
        
        for (int i = 0; i < 26; ++i) {
            if (!node->children[i]) continue;
            w.push_back('a' + i);
            helper(words, w, node->children[i]);
            w.pop_back();
        }
    }
    
    void helper(const vector<string>& words) {
        if (square.size() == n) {
            ans.push_back(square);
            return;
        }
        
        string w;
        int r = square.size();
        for (int i = 0; i < r; ++i) 
            w += square[i][r];
        Trie* node = getTrieNode(w, 0, &root);
        if (!node) return;
        helper(words, w, node);
    }
    
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        for (const auto& w : words)
            buildTrie(w, 0, &root);
        n = words[0].length();
        
        for (const auto& w : words) {
            square.push_back(w);
            helper(words);
            square.pop_back();
        }
        
        return ans;
    }
};