// 248. Strobogrammatic Number III
// https://leetcode.com/problems/strobogrammatic-number-iii/

// Runtime: 88 ms, faster than 43.39% of C++ online submissions for Strobogrammatic Number III.
// Memory Usage: 6.3 MB, less than 80.95% of C++ online submissions for Strobogrammatic Number III.
    
class Solution {
    bool le(const string& l, const string& r) {
        const int L = l.length();
        const int R = r.length(); 
        
        if (L > R) return false;
        if (L < R) return true;
        
        return l <= r;
    }
    
    void dfs(const string& low, const string& high, string num, int i, int& ans) {
        // side
        static const vector<char> S = {'1', '6', '8', '9'};
        // middle
        static const vector<char> M = {'0', '1', '8'};
        // others
        static const vector<char> N = {'0', '1', '6', '8', '9'};
        // none
        static const vector<char> X = {};
        
        static const unordered_map<char, char> P{
            {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'},
        };
        
        const int L = num.length();
        // L == 1:    num = N
        // L is odd:  num = S[N]M[N]S
        // L is even: num = S[N][N]S
        
        auto* V = &X;
        if (i > L / 2) return;
        else if (L == 1) V = &M;
        else if (i == 0) V = &S;
        else if (i == L / 2 && (L & 1)) V = &M;
        else if (i < L / 2) V = &N;
        
        int j = L - 1 - i;
        bool done = i == j || i + 1 == j;
        for (char c : *V) {
            num[i] = c;
            num[j] = P.at(c);
            if (done && le(low, num) && le(num, high)) {
                ++ans;
                // cout << num << ' ';
            }
            dfs(low, high, num, i + 1, ans);
        }
    }
    
public:
    int strobogrammaticInRange(string low, string high) {
        const int L = low.length();
        const int R = high.length();
        int ans = 0;
        for (int l = L; l <= R; ++l) {
            string num(l, '0');
            dfs(low, high, num, 0, ans);
        }
        return ans;
    }
};