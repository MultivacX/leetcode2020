// 474. Ones and Zeroes
// https://leetcode.com/problems/ones-and-zeroes/

// Runtime: 224 ms, faster than 76.51% of C++ online submissions for Ones and Zeroes.
// Memory Usage: 9.7 MB, less than 87.06% of C++ online submissions for Ones and Zeroes.

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const auto& str : strs) {
            int cnt0 = 0;
            int cnt1 = 0;
            for (auto c : str)
                c == '0' ? ++cnt0 : ++cnt1;
            
            for (int i = m; i >= cnt0; --i) 
                for (int j = n; j >= cnt1; --j) 
                    dp[i][j] = max(dp[i][j], 1 + dp[i - cnt0][j - cnt1]);
        }
        return dp[m][n];    
    }
};

// Time Limit Exceeded
// 20 / 69 test cases passed.
class Solution {
    int ans = 0;
    
    vector<int> count(const string& str, int m, int n) {
        int cnt0 = 0;
        int cnt1 = 0;
        for (const char& c : str) c == '0' ? ++cnt0 : ++cnt1;
        return {cnt0, cnt1};
    }
    
    void find(const vector<string>& strs, int m, int n, int idx, int cur) {
        ans = max(ans, cur);
        if (idx >= strs.size()) return;
        
        for (int i = idx; i < strs.size(); ++i) {
            if (i > idx && strs[i - 1] == strs[i]) continue;
            auto cnt = count(strs[i], m, n);
            if (cnt[0] > m || cnt[1] > n) continue;
            find(strs, m - cnt[0], n - cnt[1], i + 1, cur + 1);
        }
    }
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        find(strs, m, n, 0, 0);
        return ans;    
    }
};