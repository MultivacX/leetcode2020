// 132. Palindrome Partitioning II

// Runtime: 8 ms, faster than 92.92% of C++ online submissions for Palindrome Partitioning II.
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Palindrome Partitioning II.

class Solution {
public:
    int minCut(string s) {
        const int n = s.length();
        if (n <= 1) return 0;
        
        vector<int> cuts(n + 1, 0);
        for (int i = 0; i <= n; ++i)
            cuts[i] = i - 1;
        for (int i = 0; i <= n; ++i) {
            cout << "odd:" << endl;
            for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; ++j) {
                // cuts[i - j] s[i - j] ... s[i] ... s[i + j] cuts[i + j + 1]
                cuts[i + j + 1] = min(cuts[i + j + 1], 1 + cuts[i - j]);
                // printf("s[%d]:%c==s[%d]:%c, ", i - j, s[i - j], i + j, s[i + j]);
            }
            
            cout << "even:" << endl;
            for (int j = 1; i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + j]; ++j) {
                // cuts[i - j + 1] s[i - j + 1] ... s[i] s[i + 1] ... s[i + j] cuts[i + j + 1]
                cuts[i + j + 1] = min(cuts[i + j + 1], 1 + cuts[i - j + 1]);
                // printf("s[%d]:%c==s[%d]:%c, ", i - j + 1, s[i - j + 1], i + j, s[i + j]);
            }
        }
        return cuts[n];
    }
};

// Time Limit Exceeded
// 26 / 29 test cases passed.
/*class Solution {
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
};*/
/*class Solution {
public:
    unordered_map<string, int> m;
    
    int minCut(string s) {
        auto it = m.find(s);
        if (it != m.end()) 
            return m[s];
        
        if (isPalindrome(s)) {
            m.insert({s, 0});
            return 0;
        }
        
        int ans = INT_MAX;
        for (int l = 1; l < s.length(); ++l) {
            ans = min(ans, minCut(s.substr(0, l)) + 1 + minCut(s.substr(l)));
        }
        m.insert({s, ans});
        return m[s];
    }
    
    bool isPalindrome(const string& s) {
        int begin = 0;
        int end = s.length();
        while (begin < end) {
            if (s[begin] != s[end - 1])
                return false;
            ++begin;
            --end;
        }
        return true;
    }
};*/