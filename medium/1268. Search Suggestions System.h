// 1268. Search Suggestions System

// Runtime: 132 ms, faster than 44.07% of C++ online submissions for Search Suggestions System.
// Memory Usage: 92.2 MB, less than 100.00% of C++ online submissions for Search Suggestions System.

class Trie {
public:
    Trie(char _c) : c(_c) {}
    
    char c;
    string word;
    Trie* children[26] = {nullptr};
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* root = new Trie(0);
        for (const string& s : products) buildTrie(s, 0, root);
        
        vector<vector<string>> ans;
        for (int i = 0; i < searchWord.length(); ++i) {
            vector<string> words;
            string s(searchWord.substr(0, i + 1));
            search(s, 0, root, words);
            ans.push_back(words);
        }
        return ans;
    }
    
    void buildTrie(const string& s, int idx, Trie* root) {
        if (idx >= s.length()) return;
        
        int i = s[idx] - 'a';
        bool isWord = idx + 1 == s.length();
        if (!root->children[i]) root->children[i] = new Trie(s[idx]);
        
        if (!isWord) buildTrie(s, idx + 1, root->children[i]);
        else root->children[i]->word = s;
    }
    
    void search(const string& s, int idx, Trie* root, vector<string>& words) {
        if (idx >= s.length()) {
            if (words.size() == 3) return;
            if (!root->word.empty()) words.push_back(root->word);
            for (int i = 0; i < 26; ++i) {
                if (!root->children[i]) continue;
                search(s, idx, root->children[i], words);
            }
        } else {
            int i = s[idx] - 'a';
            if (!root->children[i]) return;
            search(s, idx + 1, root->children[i], words);
        }
    }
};