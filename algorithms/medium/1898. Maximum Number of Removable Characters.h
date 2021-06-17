// 1898. Maximum Number of Removable Characters
// https://leetcode.com/problems/maximum-number-of-removable-characters/

// Runtime: 216 ms, faster than 84.63% of C++ online submissions for Maximum Number of Removable Characters.
// Memory Usage: 76.9 MB, less than 71.64% of C++ online submissions for Maximum Number of Removable Characters.
    
class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        vector<int> removed(s.length(), INT_MAX);
        for (int i = 0; i < removable.size(); ++i)
            removed[removable[i]] = i;
        
        int l = 0, r = removable.size(), k = 0;
        while (l < r) {
            int m = l + (r - l) / 2;
            int i = 0, j = 0;
            while (i < s.length() && j < p.length()) {
                if (s[i] == p[j] && removed[i] > m)
                    ++j;
                ++i;
            }
            if (j == p.length()) {
                l = m + 1;
                k = l;
            } else {
                r = m;
            }
        }
        return k;
    }
};