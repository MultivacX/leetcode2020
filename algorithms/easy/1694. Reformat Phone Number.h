// 1694. Reformat Phone Number
// https://leetcode.com/problems/reformat-phone-number/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reformat Phone Number.
// Memory Usage: 6.6 MB, less than 43.40% of C++ online submissions for Reformat Phone Number.
    
class Solution {
public:
    string reformatNumber(string number) {
        string t, s;
        for (char c : number) if (isdigit(c)) t += c;
        const int n = t.size();
        for (int i = 0; i < n; ) {
            if (i + 4 == n) {
                s += t[i++];
                s += t[i++];
                s += '-';
                s += t[i++];
                s += t[i++];
            } else if (i + 3 == n) {
                s += t[i++];
                s += t[i++];
                s += t[i++];
            } else if (i + 2 == n) {
                s += t[i++];
                s += t[i++];
            } else {
                s += t[i++];
                s += t[i++];
                s += t[i++];
                s += '-';
            }
        }
        return s;
    }
};