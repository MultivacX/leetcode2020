// 1881. Maximum Value after Insertion
// https://leetcode.com/problems/maximum-value-after-insertion/

// Runtime: 88 ms, faster than 70.54% of C++ online submissions for Maximum Value after Insertion.
// Memory Usage: 35.5 MB, less than 42.32% of C++ online submissions for Maximum Value after Insertion.
    
class Solution {
public:
    string maxValue(string n, int x) {
        string s;
        int i = 0;
        
        if (n[0] == '-') {
            i = 1;
            while (i < n.length() && n[i] - '0' <= x)
                ++i;
        } else {
            while (i < n.length() && n[i] - '0' >= x)
                ++i;
        }
        
        s += n.substr(0, i);
        s.push_back('0' + x);
        if (i < n.length()) s += n.substr(i);
        return s;
    }
};