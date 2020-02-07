// 132. Palindrome Partitioning II

// Time Limit Exceeded
// 26 / 29 test cases passed.
class Solution {
public:
    int minCut(string s) {
        return cut(s, 0, s.length());
    }
    
    int cut(const string& s, int begin, int end) {
        if (isPalindrome(s, begin, end))
            return 0;
        
        if (c[begin][end] != 0)
            return c[begin][end];
        
        int ans = s.length();
        for (int i = begin + 1; i < end; ++i) {
            ans = min(ans, 1 + cut(s, 0, i) + cut(s, i, end));
            if (ans == 1)
                break;
        }
        c[begin][end] = ans;
        return ans;
    }
    
    bool isPalindrome(const string& s, int begin, int end) {
        if (end - begin == 1) 
            return true;
        
        int ti = begin;
        int tj = end - 1;
        auto it = m[begin].find(end);
        if (it == m[begin].end()) {
            m[begin][end] = true;
            while (ti < tj) {
                if (s[ti++] != s[tj--]) {
                    m[begin][end] = false;
                    break;
                }
            }
        }
        return m[begin][end];
    }
    
    unordered_map<int, unordered_map<int, bool>> m;
    unordered_map<int, unordered_map<int, int>> c;
};