// 247. Strobogrammatic Number II
// https://leetcode.com/problems/strobogrammatic-number-ii/

// Runtime: 80 ms, faster than 8.65% of C++ online submissions for Strobogrammatic Number II.
// Memory Usage: 20.5 MB, less than 28.22% of C++ online submissions for Strobogrammatic Number II.
    
class Solution {
    vector<string> ans;
    string s;
    
    void dfs(int n, int i) {
        static const vector<char> F = {'1', '6', '8', '9'};
        static const vector<char> N = {'0', '1', '6', '8', '9'};
        static const vector<char> M = {'0', '1', '8'};    
        
        if (i > n / 2 - 1) {
            string t(s);
            reverse(begin(t), end(t));
            for (auto& c : t) {
                if (c == '6') c = '9';
                else if (c == '9') c = '6';
            }
            if (n & 1) {
                for (char c : M) 
                    ans.push_back(s + c + t);
            } else {
                ans.push_back(s + t);
            }
            return;
        }
        
        const auto& V = i == 0 ? F : N;
        for (char c : V) {
            s.push_back(c);
            dfs(n, i + 1);
            s.pop_back();
        }
    }
    
public:
    vector<string> findStrobogrammatic(int n) {
        if (n <= 0) return {};
        // if (n == 1) return {"0", "1", "8"};
        dfs(n, 0);
        return ans;
    }
};