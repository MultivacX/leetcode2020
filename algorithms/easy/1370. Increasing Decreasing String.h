// 1370. Increasing Decreasing String
// https://leetcode.com/problems/increasing-decreasing-string/

// Runtime: 8 ms, faster than 74.93% of C++ online submissions for Increasing Decreasing String.
// Memory Usage: 7.4 MB, less than 97.92% of C++ online submissions for Increasing Decreasing String.
    
class Solution {
public:
    string sortString(string s) {
        vector<int> counts(26, 0);
        for (char c : s) ++counts[c - 'a'];
        const int N = s.length();
        int n = 0;
        string t(s);
        while (n < N) {
            for (int i = 0; i < 26; ++i) 
                if (counts[i]-- > 0)
                    t[n++] = i + 'a';
            for (int i = 25; i >= 0; --i) 
                if (counts[i]-- > 0)
                    t[n++] = i + 'a';
        }
        return t;
    }
};