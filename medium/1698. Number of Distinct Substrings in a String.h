// 1698. Number of Distinct Substrings in a String
// https://leetcode.com/problems/number-of-distinct-substrings-in-a-string/

// TLE
class Solution {
    struct Trie {
        Trie() {}
        unordered_map<char, Trie*> children;
    };
    
    Trie root;
    int ans = 0;
    
    void build(const string& word, int i, Trie* node) {
        if (i >= word.length()) 
            return;
        
        if (node->children.count(word[i]) == 0) {
            node->children[word[i]] = new Trie;
            ++ans;
        }
        build(word, i + 1, node->children[word[i]]);
    }
    
public:
    int countDistinct(string s) {
        for (int i = 0; i < s.length(); ++i)
            build(s, i, &root);
        return ans;
    }
};

// TLE
class Solution {
    struct Trie {
        Trie() : children(26, nullptr) {}
        vector<Trie*> children;
    };
    
    Trie root;
    int ans = 0;
    
    void build(const string& word, int i, Trie* node) {
        if (i >= word.length()) 
            return;
        
        int j = word[i] - 'a';
        if (!node->children[j]) {
            node->children[j] = new Trie;
            ++ans;
        }
        build(word, i + 1, node->children[j]);
    }
    
public:
    int countDistinct(string s) {
        for (int i = 0; i < s.length(); ++i)
            build(s, i, &root);
        return ans;
    }
};