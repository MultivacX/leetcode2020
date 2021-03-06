// 131. Palindrome Partitioning

// Runtime: 28 ms, faster than 68.06% of C++ online submissions for Palindrome Partitioning.
// Memory Usage: 14.7 MB, less than 83.33% of C++ online submissions for Palindrome Partitioning.

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> v;
        vector<vector<string>> ans;
        partition(s, 0, v, ans);
        return ans;
    }
    
    void partition(const string& s, int i, vector<string>& v, vector<vector<string>>& ans) {
        if (i >= s.length()) {
            ans.emplace_back(v);
            return;
        }
        
        for (int len = 1; len <= s.length() - i; ++len) {
            if (!isPalindrome(s, i, len))
                continue;
            
            v.emplace_back(s.substr(i, len));
            partition(s, i + len, v, ans);
            v.pop_back();
        }
    }
    
    bool isPalindrome(const string& s, int i, int len) {
        if (len == 1) 
            return true;
        
        int ti = i;
        int tj = len - 1 + i;
        auto it = m[i].find(len);
        if (it == m[i].end()) {
            m[i][len] = true;
            while (ti < tj) {
                if (s[ti++] != s[tj--]) {
                    m[i][len] = false;
                    break;
                }
            }
        }
        return m[i][len];
    }
    
    unordered_map<int, unordered_map<int, bool>> m;
};


class Solution {
    vector<vector<string>> ans;
    
    bool isPalindrome(const string& s, int i, int j) {
        if (i >= j) return true;
        while (i < j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }
    
    void dfs(const string& s, int i, vector<string>& strs) {
        const int n = s.length();
        if (i >= n) ans.push_back(strs);
        
        for (int j = i; j < n; ++j) {
            if (!isPalindrome(s, i, j)) 
                continue;
            strs.push_back(s.substr(i, j - i + 1));
            dfs(s, j + 1, strs);
            strs.pop_back();
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        const int n = s.length();
        
        vector<string> strs;
        dfs(s, 0, strs);
        return ans;
    }
};


// Runtime: 104 ms, faster than 84.84% of C++ online submissions for Palindrome Partitioning.
// Memory Usage: 75.9 MB, less than 45.50% of C++ online submissions for Palindrome Partitioning.
    
class Solution {
    vector<vector<int>> memo;
    vector<vector<string>> ans;
    
    bool isPalindrome(const string& s, int i, int j) {
        if (i >= j) return true;
        int& m = memo[i][j];
        if (m != 0) return m == 1;
        m = -1;
        while (i < j) 
            if (s[i++] != s[j--]) 
                return false;
        m = 1;
        return true;
    }
    
    void dfs(const string& s, int i, vector<string>& strs) {
        const int n = s.length();
        if (i >= n) ans.push_back(strs);
        
        for (int j = i; j < n; ++j) {
            if (!isPalindrome(s, i, j)) 
                continue;
            strs.push_back(s.substr(i, j - i + 1));
            dfs(s, j + 1, strs);
            strs.pop_back();
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        const int n = s.length();
        memo = vector<vector<int>>(n, vector<int>(n, 0));
        
        vector<string> strs;
        dfs(s, 0, strs);
        return ans;
    }
};