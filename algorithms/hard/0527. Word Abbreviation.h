// 527. Word Abbreviation
// https://leetcode.com/problems/word-abbreviation/

// Runtime: 380 ms, faster than 22.89% of C++ online submissions for Word Abbreviation.
// Memory Usage: 371.9 MB, less than 15.66% of C++ online submissions for Word Abbreviation.
    
class Solution {
    struct Trie {
        Trie(int cnt = 0) : k(cnt), children(26) {}
        int k;
        vector<Trie*> children;
    };
    
    unordered_map<int, Trie> trees;
    
    Trie* getRoot(const string& word) {
        int key = word.back() + (word.length() << 9);
        return &trees[key];
    }
    
    void build(const string& word, int i, Trie* node) {
        if (i >= word.length()) return;
        
        int j = word[i] - 'a';
        if (!node->children[j]) 
            node->children[j] = new Trie(0);
        node->children[j]->k += 1;
        build(word, i + 1, node->children[j]);
    }
    
    void abbr(const string& word, int& i, Trie* node) {
        if (i >= word.length()) return;
        
        int j = word[i] - 'a';
        if (node->children[j]->k == 1) return;
        
        abbr(word, ++i, node->children[j]);
    }
    
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        const int N = dict.size();
        for (const auto& word : dict)
            if (word.length() > 3)
                build(word, 0, getRoot(word));
        
        vector<string> ans(N);
        for (int i = 0; i < N; ++i) {
            const int M = dict[i].length();
            if (dict[i].length() <= 3) {
                ans[i] = dict[i];
            } else {
                // [0, j] m [last]
                int j = 0;
                abbr(dict[i], j, getRoot(dict[i]));
                int m = M - j - 2;
                if (m < 2) ans[i] = dict[i];
                else ans[i] = dict[i].substr(0, j + 1) + to_string(m) + dict[i].back();
            }
        }
        return ans;
    }
};