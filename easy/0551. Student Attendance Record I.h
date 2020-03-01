// 551. Student Attendance Record I

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Student Attendance Record I.
// Memory Usage: 7.8 MB, less than 100.00% of C++ online submissions for Student Attendance Record I.

class Solution {
public:
    bool checkRecord(string s) {
        const int n = s.length();
        int A = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'A' && ++A > 1) 
                return false;
            else if (i > 1 && s[i] == 'L' && s[i - 1] == 'L' && s[i - 2] == 'L') 
                return false;
        }
        return true;
    }
};