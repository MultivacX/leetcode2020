// 1528. Shuffle String
// https://leetcode.com/problems/shuffle-string/

// Runtime: 8 ms, faster than 94.53% of C++ online submissions for Shuffle String.
// Memory Usage: 15.2 MB, less than 100.00% of C++ online submissions for Shuffle String.
    
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string t(s);
        for (int i = 0; i < s.length(); ++i)
            t[indices[i]] = s[i];
        return t;
    }
};