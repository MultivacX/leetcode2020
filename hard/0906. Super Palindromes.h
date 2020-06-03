// 906. Super Palindromes
// https://leetcode.com/problems/super-palindromes/submissions/

// Runtime: 440 ms, faster than 36.36% of C++ online submissions for Super Palindromes.
// Memory Usage: 35.8 MB, less than 100.00% of C++ online submissions for Super Palindromes.

class Solution {
    bool is_palindrome(uint64_t p) {
        string s(to_string(p));
        int i = 0;
        int j = s.length() - 1;
        while (i < j) if (s[i++] != s[j--]) return false;
        return true;
    }
    
    uint64_t get_palindrome(uint64_t v) {
        string s(to_string(v));
        int i = 0;
        int j = s.length() - 1;
        while (i < j) s[j--] = s[i++];
        return stoll(s);
    }
    
    uint64_t palindrome_plus_1(uint64_t v) {
        string s(to_string(v));
        const int N = s.length();
        int k = N / 2;
        int carry = 1;
        while (k < N) {
            int val = carry + s[k] - '0';
            carry = val / 10;
            s[k] = val % 10 + '0';
            ++k;
        }
        // cout << v << ", ";
        if (carry) {
            string t(N + 1, '0');
            t[0] = t[N] = '1';
            // cout << t << endl;
            return stoll(t);
        } else {
            int i = 0;
            int j = N - 1;
            while (i < j) s[i++] = s[j--];
            // cout << s << endl;
            return stoll(s);
        }
    }
    
public:
    int superpalindromesInRange(string L, string R) {
        const uint64_t L_ = stoll(L);
        const uint64_t R_ = stoll(R);
        
        uint64_t l = get_palindrome(sqrt(L_));
        int ans = 0;
        while (l * l <= R_) {
            // cout << l << ", " << l * l << endl;
            if (l * l < L_ || !is_palindrome(l * l)) {
                l = palindrome_plus_1(l);
                continue;
            }
            l = palindrome_plus_1(l);
            ++ans;
        }
        return ans;
    }
};