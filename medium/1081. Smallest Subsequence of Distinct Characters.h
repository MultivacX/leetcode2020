// 1081. Smallest Subsequence of Distinct Characters

// Runtime: 4 ms, faster than 51.31% of C++ online submissions for Smallest Subsequence of Distinct Characters.
// Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Smallest Subsequence of Distinct Characters.

class Solution {
public:
    string smallestSubsequence(string text) {
        vector<int> cnt(26, 0);
        for (const auto& c : text) ++cnt[c - 'a'];
        vector<bool> used(26, false);
        
        string ans;
        for (const auto& c : text) {
            int i = c - 'a'; 
            
            while (!used[i] && !ans.empty() && ans.back() > c && cnt[ans.back() - 'a'] > 0) {
                int j = ans.back() - 'a';
                used[j] = false;
                ans.pop_back();
            }
            
            --cnt[i];
            if (!used[i]) {
                used[i] = true;
                ans.push_back(c);    
            }
        }
        return ans;
    }
};