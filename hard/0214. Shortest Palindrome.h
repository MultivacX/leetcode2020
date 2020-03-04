// 214. Shortest Palindrome

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