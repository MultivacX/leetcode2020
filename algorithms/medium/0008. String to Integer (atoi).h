// 8. String to Integer (atoi)

// Runtime: 8 ms, faster than 13.44% of C++ online submissions for String to Integer (atoi).
// Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for String to Integer (atoi).

class Solution {
public:
    int myAtoi(string str) {
        const int N = str.length();
        
        int i = 0;
        
        // skip ' '
        while (i < N && str[i] == ' ') ++i;
        
        // sign
        if (i >= N) return 0;
        bool positive = true;
        if (!isdigit(str[i])) {
            if (str[i] == '+') ++i, positive = true; 
            else if (str[i] == '-') ++i, positive = false; 
            else return 0;
        }
        
        // not a digit
        if (i >= N || !isdigit(str[i])) return 0;
        
        int64_t ans = 0;
        while (i < N && isdigit(str[i])) {
            ans = ans * 10 + str[i] - '0';
            ++i;
            if (positive && ans >= (int64_t)INT_MAX) return INT_MAX;
            else if (!positive && -ans <= (int64_t)INT_MIN) return INT_MIN;
        }
        return positive ? ans : -ans;
    }
};

class Solution {
public:
    int myAtoi(string s) {
        const int n = s.length();
        int i = 0;
        
        while (i < n && s[i] == ' ') ++i;
        if (i == n) return 0;
        
        int64_t sign = 1;
        if (s[i] == '+') ++i;
        else if (s[i] == '-') ++i, sign = -1;
        if (i == n) return 0;
        
        int64_t ans = 0;
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + s[i++] - '0';
            if (ans * sign < INT_MIN) return INT_MIN;
            if (ans * sign > INT_MAX) return INT_MAX;
        }
        ans *= sign;
        return ans;
    }
};