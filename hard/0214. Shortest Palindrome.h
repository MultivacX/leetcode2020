// 214. Shortest Palindrome

// Memory Limit Exceeded
// 120 / 120 test cases passed, but took too much memory.
class Solution {
public:
    string shortestPalindrome(string s) {
        const int n = s.length();
        string r(s.rbegin(), s.rend());
        for (int l = n; l > 0; --l) {
            if (s.substr(0, l) == r.substr(n - l)) {
                // cout << s.substr(0, l) << endl;
                return r.substr(0, n - l) + s;
            }
        }
        return s;
    }
};

// Time Limit Exceeded
// 120 / 120 test cases passed, but took too long.
class Solution {
public:
    string shortestPalindrome(string s) {
        for (int k = s.length() - 1; k >= 0; --k) {
            int i = 0;
            int j = k;
            while (i < j && s[i] == s[j]) {
                ++i;
                --j;
            }
            if (i >= j) {
                if (k == s.length() - 1) return s;
                string front(s.substr(k + 1));
                reverse(front.begin(), front.end());
                return front + s;
            }
        }   
        return s;
    }
};