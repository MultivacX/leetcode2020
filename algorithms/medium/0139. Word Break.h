// 139. Word Break

// Runtime: 4 ms, faster than 94.25% of C++ online submissions for Word Break.
// Memory Usage: 10.7 MB, less than 71.70% of C++ online submissions for Word Break.

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty() || wordDict.empty())
            return false;
        
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        for (int l = 1; l <= s.length(); ++l) {
            for (int k = l - 1; k >= 0 && !dp[l]; --k) {
                // cout << l << ", " << k << " = " << s.substr(k, l - k) << endl;
                dp[l] = dp[k] && words.count(s.substr(k, l - k));
            }
        }
        return dp.back();
    }
};

// Time Limit Exceeded
// 29 / 36 test cases passed.
/*class Solution {
public:
    class Trie {
    public:
        string word;
        Trie* children[26] = {nullptr};
        
        static Trie* build(vector<string>& wordDict) {
            auto root = new Trie;
            for (const string& word : wordDict)
                build(root, 0, word);
            return root;
        }
        
        static void build(Trie* t, int i, const string& word) {
            if (i == word.length()) {
                t->word = word;
                return;
            }
            
            int idx = word[i] - 'a';
            if (!t->children[idx])
                t->children[idx] = new Trie;
            build(t->children[idx], i + 1, word);
         }
    };

    bool wordBreak(string s, vector<string>& wordDict) {
        auto root = Trie::build(wordDict);
        return wordBreak(s, 0, root, root);
    }
    
    bool wordBreak(const string& s, int i, Trie* root, Trie* t) {
        if (i == s.length())
            return t->word.length();
        
        auto child = t->children[s[i] - 'a'];
        if (child == nullptr) {
            if (root == t)
                return false;
            return t->word.length() && wordBreak(s, i, root, root);
        }
        return wordBreak(s, i + 1, root, child) || (t->word.length() && wordBreak(s, i, root, root));
    }
};*/

// misunderstand
/*class Solution {
public:
    class Trie {
    public:
        string word;
        Trie* children[26] = {nullptr};
        
        static Trie* build(vector<string>& wordDict) {
            auto root = new Trie;
            for (const string& word : wordDict)
                build(root, 0, word);
            return root;
        }
        
        static void build(Trie* t, int i, const string& word) {
            if (i == word.length()) {
                t->word = word;
                return;
            }
            
            int idx = word[i] - 'a';
            if (!t->children[idx])
                t->children[idx] = new Trie;
            build(t->children[idx], i + 1, word);
         }
    };

    Trie* root;
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int words_length = 0;
        for (const string& word : wordDict)
            words_length += word.length();
        if (s.length() < words_length)
            return false;
        
        root = Trie::build(wordDict);
        for (int i = 0; i <= s.length() - words_length; ++i) {
            unordered_set<string> visited;
            if (wordBreak(s, i, visited, words_length, root))
                return true;
        }
        return false;
    }
    
    bool wordBreak(const string& s, 
                   int i,
                   unordered_set<string>& visited, 
                   int words_length,
                   Trie* t) {
        if (words_length == 0) 
            return true;
        
        auto child = t->children[s[i] - 'a'];
        if (!child)
            return false;
        if (child->word.length() > 0) {
            if (visited.count(child->word))
                return false;
            visited.insert(child->word);
            return wordBreak(s, i + 1, visited, words_length - 1, root);
        }
        return wordBreak(s, i + 1, visited, words_length - 1, child);
    }
};*/