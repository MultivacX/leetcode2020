// 906. Super Palindromes

class Solution {
    uint64_t get_palindrome(int& len, uint64_t h, int& hl) {
        string L(to_string(h));
        if (L.length() > hl) {
            L.pop_back();
            len += 1;
            hl = (len + 1) >> 1;
        }
        string R(L);
        if (len & 1) R.pop_back();
        reverse(begin(R), end(R));
        return stoll(L + R);
    }
    
    bool is_palindrome(uint64_t p) {
        string s(to_string(p));
        int i = 0;
        int j = s.length() - 1;
        while (i < j) if (s[i++] != s[j--]) return false;
        return true;
    }
    
public:
    int superpalindromesInRange(string L, string R) {
        uint64_t l = stoll(L);
        uint64_t r = stoll(R);
        
        int len = L.length();
        int hl = (len + 1) >> 1;
        uint64_t h = stoll(L.substr(0, hl));
        
        int ans = 0;
        while (true) {
            uint64_t p = get_palindrome(len, h, hl);
            if (p > r) break;
            h += 1;
            if (p < l) continue;
            
            uint64_t s = sqrt(p);
            if (s * s == p && is_palindrome(s)) ++ans;
            // cout << p << " " << s << endl;
        }
        return ans;
    }
};