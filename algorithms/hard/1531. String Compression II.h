// 1531. String Compression II
// https://leetcode.com/problems/string-compression-ii/

// Runtime: 68 ms, faster than 59.48% of C++ online submissions for String Compression II.
// Memory Usage: 19.5 MB, less than 43.14% of C++ online submissions for String Compression II.
    
class Solution {
    int compress(int length) {
        if (length <= 1) return length;
        if (length <= 9) return 2;
        if (length <= 99) return 3;
        return 4;
    }
    
    int dp(const string& s, int k, int start, vector<vector<int>>& memo) {
        const int n = s.length();
        if (k < 0) return n;
        if (start + k >= n) return 0;
        if (memo[start][k] != -1) return memo[start][k];
        
        vector<int> count(26);
        int ans = n;
        for (int i = start, most = 0; i < n; ++i) {
            // s[start ... i]
            most = max(most, ++count[s[i] - 'a']);
            int ori_len = i - start + 1;
            int del_len = ori_len - most;
            int cur_len = compress(most);
            ans = min(ans, cur_len + dp(s, k - del_len, i + 1, memo));
        }
        memo[start][k] = ans;
        return ans;
    }
    
public:
    int getLengthOfOptimalCompression(string s, int k) {
        const int n = s.length();
        // memo[start][k] = compressed_minimum_length(s.substr(start))
        vector<vector<int>> memo(n, vector<int>(k + 1, -1));
        return dp(s, k, 0, memo);
    }
};