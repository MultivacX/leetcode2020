// 420. Strong Password Checker
// https://leetcode.com/problems/strong-password-checker/

class Solution {
    int hasLower = 0;
    int hasUpper = 0;
    int hasDigit = 0;
    priority_queue<int> repeatingLower;
    priority_queue<int> repeatingUpper;
    priority_queue<int> repeatingDigit;
    priority_queue<int> repeatingOther;
    
    void init(const string& password) {
        const int n = password.length();
        string t;
        int i = 0;
        while (i < n) {
            if ('a' <= password[i] && password[i] <= 'z')
                hasLower = 1;
            else if ('A' <= password[i] && password[i] <= 'Z')
                hasUpper = 1;
            else if ('0' <= password[i] && password[i] <= '9')
                hasDigit = 1;
                
            if (t.empty() || t.back() == password[i]) {
                t.push_back(password[i]);
            } else {
                if (t.length() >= 3) {
                    if ('a' <= t.back() && t.back() <= 'z')
                        repeatingLower.push(t.length());
                    else if ('A' <= t.back() && t.back() <= 'Z')
                        repeatingUpper.push(t.length());
                    else if ('0' <= t.back() && t.back() <= '9')
                        repeatingDigit.push(t.length());
                    else
                        repeatingOther.push(t.length());
                }
                t.clear();
            }
            ++i;
        }
    }
    
public:
    int strongPasswordChecker(string password) {
        init(password);
        
        const int n = password.length();
        int types = hasLower + hasUpper + hasDigit;
        
        if (n < 6) {
            // !!!! -> !!A!1e
            if (types == 0) return max(3, 6 - n);
            
        } else if (6 <= n && n <= 20) {
            
        } else {
            
        }
        
        return 0;
    }
};