// 1930. Unique Length-3 Palindromic Subsequences
// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/

// Runtime: 300 ms, faster than 73.93% of C++ online submissions for Unique Length-3 Palindromic Subsequences.
// Memory Usage: 265.7 MB, less than 5.04% of C++ online submissions for Unique Length-3 Palindromic Subsequences.
    
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        const int n = s.length();
        
        vector<vector<int>> pre_cnt;
        vector<int> cnt(26);
        cnt[s[0] - 'a'] = 1;
        pre_cnt.push_back(cnt);
        
        vector<int> right_most(26, -1);
        right_most[s[0] - 'a'] = 0;
        
        for (int i = 1; i < n; ++i) {
            int j = s[i] - 'a';
            
            pre_cnt.push_back(pre_cnt.back());
            pre_cnt.back()[j] += 1;
            
            right_most[j] = i;
        }
        
        int ans = 0;
        for (int l = 0; l + 2 < n; ++l) {
            int j = s[l] - 'a';
            
            int r = right_most[j];
            if (r - l < 2) continue;
            
            for (int i = 0; i < 26; ++i)
                ans += pre_cnt[r - 1][i] > pre_cnt[l][i] ? 1 : 0;
            
            right_most[j] = -1;
        }
        return ans;
    }
};