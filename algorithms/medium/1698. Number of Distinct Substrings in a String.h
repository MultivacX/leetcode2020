// 1698. Number of Distinct Substrings in a String
// https://leetcode.com/problems/number-of-distinct-substrings-in-a-string/

// Runtime: 40 ms, faster than 85.71% of C++ online submissions for Number of Distinct Substrings in a String.
// Memory Usage: 6.8 MB, less than 100.00% of C++ online submissions for Number of Distinct Substrings in a String.
    
class Solution {    
public:
    int countDistinct(string s) {
        // s : [0, ..., N-1]
        //             distinct cnt _ suffix end with s[i]
        // dp[i] = L : [0, ... , i-L] [i+1-L, ..., i] 
        const int N = s.length();
        vector<int> dp(N, 0);
        for (int l = 1; l <= N; ++l) {
            for (int i = 0, len = 0; i + l <= N; ++i) {
                if (s[i] == s[i + l]) ++len;
                else len = 0;
                dp[i] = max(dp[i], len);
            }
        }
        int cnt = 0;
        for (int i = 0; i < N; ++i) 
            cnt += i + 1 - dp[i];
        return cnt;
    }
};

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

// TLE
class Solution {    
public:
    int countDistinct(string s) {
        const int N = s.length();
        unordered_set<string> strs;
        for (int l = 1; l <= N; ++l) {
            for (int i = 0; i + l <= N; ++i) {
                strs.insert(s.substr(i, l));
            }
        }
        return strs.size();
    }
};