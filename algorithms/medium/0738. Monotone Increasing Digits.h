// 738. Monotone Increasing Digits

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Monotone Increasing Digits.
// Memory Usage: 7.5 MB, less than 100.00% of C++ online submissions for Monotone Increasing Digits.

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if (N < 10) return N;
        
        string n(to_string(N));
        for (int i = 0; i < n.length() - 1; ++i) {
            if (n[i] <= n[i + 1]) continue;
            
            for (int j = i + 1; j < n.length(); ++j)
                n[j] = '9';
            
            if (n[i] == '1') {
                n[0] = '0';
                for (int j = 1; j <= i; ++j) n[j] = '9';
            } else {
                --n[i];
                while (i > 0 && n[i - 1] > n[i]) {
                    n[i] = '9';
                    --n[--i];
                }
            }
            
            break;
        }
        return stoi(n);
    }
};