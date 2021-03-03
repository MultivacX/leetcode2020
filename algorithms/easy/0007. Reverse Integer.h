// 7. Reverse Integer

// Runtime: 4 ms, faster than 48.43% of C++ online submissions for Reverse Integer.
// Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Reverse Integer.

class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        int64_t X = abs((int64_t)x);
        int64_t ans = 0;
        while (X > 0) {
            ans = ans * 10 + X % 10;
            X /= 10;
        }
        if (x < 0) ans *= -1;
        return ans > (int64_t)INT_MAX || ans < (int64_t)INT_MIN ? 0 : ans;
    }
};


class Solution {
public:
    int reverse(int x) {
        static const string STR_MAX = to_string(INT_MAX);
        static const string STR_MIN = to_string(INT_MIN);
        
        string str = to_string(x);
        const int n = str.length();
        const int offset = x >= 0 ? 0 : 1;
        const auto& STR = x >= 0 ? STR_MAX : STR_MIN;
        const int N = x >= 0 ? STR_MAX.length() : STR_MIN.length();
        std::reverse(begin(str) + offset, end(str));
        for (int i = offset; i < n && n == N; ++i) {
            if (str[i] < STR[i]) break;
            if (str[i] == STR[i]) continue;
            return 0;
        }
        return stoi(str);
    }
};