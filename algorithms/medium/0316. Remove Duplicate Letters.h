// 316. Remove Duplicate Letters

// Runtime: 4 ms, faster than 77.86% of C++ online submissions for Remove Duplicate Letters.
// Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Remove Duplicate Letters.

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26, 0);
        for (const auto& c : s) ++cnt[c - 'a'];
        vector<bool> used(26, false);
        
        string ans;
        for (const auto& c : s) {
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