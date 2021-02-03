// 1216. Valid Palindrome III
// https://leetcode.com/problems/valid-palindrome-iii/

// Runtime: 16 ms, faster than 92.83% of C++ online submissions for Valid Palindrome III.
// Memory Usage: 14.3 MB, less than 86.55% of C++ online submissions for Valid Palindrome III.
    
class Solution {
    vector<vector<int>> memo;
    
    int makePalindrome(const string& s, int i, int j) {
        if (i >= j) return 0;
        if (i + 1 == j) return s[i] == s[j] ? 0 : 1;
        
        if (memo[i][j] != -1) return memo[i][j];
        
        int ans = 0;
        if (s[i] == s[j]) ans = makePalindrome(s, i + 1, j - 1);
        else ans = 1 + min(makePalindrome(s, i + 1, j), makePalindrome(s, i, j - 1));
        memo[i][j] = ans;
        return ans;
    }
    
public:
    bool isValidPalindrome(string s, int k) {
        const int n = s.length();
        if (n == k) return true;
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        return makePalindrome(s, 0, s.length() - 1) <= k;
    }
};

// TLE
// 48 / 50 test cases passed.
class Solution {
    int n;
    vector<vector<vector<int>>> memo;
    vector<vector<pair<int, int>>> ij;
    
    bool isPalindromic(const string& s, int& i, int& j) {
        if (i < n && j > -1 && ij[i][j].first != -1)
            return ij[i][j].first >= ij[i][j].second;
        while (i < j && s[i] == s[j])
            ++i, --j;
        ij[i][j].first = i;
        ij[i][j].second = j;
        return i >= j;
    }

    bool isValidPalindrome(const string& s, int k, int i, int j) {
        if (isPalindromic(s, i, j)) return true;
        if (k == j - i + 1) return true;
        if (k <= 0) return false;
        
        if (memo[i][j][k] != -1) return memo[i][j][k];
        
        bool ans = isValidPalindrome(s, k - 1, i + 1, j) ||
                   isValidPalindrome(s, k - 1, i, j - 1);
        memo[i][j][k] = ans;
        return ans;
    }
    
public:
    bool isValidPalindrome(string s, int k) {
        n = s.length();
        if (n == k) return true;
        memo = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        ij = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(n, {-1, -1}));
        return isValidPalindrome(s, k, 0, s.length() - 1);
    }
};

// TLE
// 44 / 50 test cases passed.
class Solution {
    int n;
    vector<vector<pair<int, int>>> ij;
    
    bool isPalindromic(const string& s, int& i, int& j) {
        if (i < n && j > -1 && ij[i][j].first != -1)
            return ij[i][j].first >= ij[i][j].second;
        while (i < j && s[i] == s[j])
            ++i, --j;
        ij[i][j].first = i;
        ij[i][j].second = j;
        return i >= j;
    }

    bool isValidPalindrome(const string& s, int k, int i, int j) {
        if (isPalindromic(s, i, j)) return true;
        if (k == j - i + 1) return true;
        if (k <= 0) return false;
        
        return isValidPalindrome(s, k - 1, i + 1, j) ||
               isValidPalindrome(s, k - 1, i, j - 1);
    }
    
public:
    bool isValidPalindrome(string s, int k) {
        n = s.length();
        if (n == k) return true;
        ij = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(n, {-1, -1}));
        return isValidPalindrome(s, k, 0, s.length() - 1);
    }
};