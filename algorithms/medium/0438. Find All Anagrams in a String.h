// 438. Find All Anagrams in a String

// Runtime: 28 ms, faster than 93.91% of C++ online submissions for Find All Anagrams in a String.
// Memory Usage: 10.4 MB, less than 78.85% of C++ online submissions for Find All Anagrams in a String.

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = p.length();
        int n = s.length();
        if (m > n)
            return {};
        
        int cnt1[26] = {0};
        int cnt2[26] = {0};
        for (const char& c : p)
            ++cnt1[c - 'a'];
        
        vector<int> ans;
        int start = -1;
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            if (cnt1[idx] == 0) {
                memset(cnt2, 0, 26 * sizeof(int));
                start = -1;
                continue;
            }
            
            if (start < 0)
                start = i;
            ++cnt2[idx];
            while (cnt2[idx] > cnt1[idx] && start < i)
                --cnt2[s[start++] - 'a'];
            
            if (i - start + 1 == m) {
                ans.push_back(start);
                --cnt2[s[start++] - 'a'];
            }
        }
        return ans;
    }
};