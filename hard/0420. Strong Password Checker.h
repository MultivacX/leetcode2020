// 420. Strong Password Checker
// https://leetcode.com/problems/strong-password-checker/

class Solution {
public:
    int strongPasswordChecker(string s) {
        int N = s.length();
        int l = 0;
        int u = 0;
        int d = 0;
        for (char c : s) {
            if (c >= 'a' && c <= 'z') ++l;
            else if (c >= 'A' && c <= 'Z') ++u;
            else if (c >= '0' && c <= '9') ++d;
        }
        return 0;
    }
};