// 306. Additive Number

// Runtime: 4 ms, faster than 65.13% of C++ online submissions for Additive Number.
// Memory Usage: 8.5 MB, less than 75.00% of C++ online submissions for Additive Number.

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        for (int i = 1; i <= n / 2; ++i) {
            string a = num.substr(0, i);
            for (int j = 1; i + j <= n * 2 / 3; ++j) {
                string b = num.substr(i, j);
                if (f(num, i + j, a, b))
                    return true;
                if (num[i] == '0')
                    break;
            }
            if (num[0] == '0')
                break;
        }
        return false;
    }
    
    bool f(string num, int idx, string a, string b) {
        // cout << "(" << num.length() << ", " << idx << ") " << a << " + " << b << endl;
        auto i = stoll(a) + stoll(b);
        if (i != 0 && num[idx] == '0')
            return false;
        
        string c = to_string(i);
        
        if (c.length() > num.length() - idx) 
            return false;
        
        if (c.length() == num.length() - idx) 
            return c == num.substr(idx);
        
        if (c != num.substr(idx, c.length()))
            return false;
        
        return f(num, idx + c.length(), b, c);
     }
};