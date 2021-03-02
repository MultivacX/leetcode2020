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
        // optim : for-loop & string s(n)
        dfs(n, 0);
        return ans;
    }
};


class Solution {
    const vector<char> same{'0', '1', '8'};
    const vector<vector<char>> rotated{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    
    void find(const int n, int i, string& s, vector<string>& ans) {
        int j = n - i - 1;
        if (i > j) {
            ans.push_back(s);
        } else if (i == j) {
            for (char c : same) {
                s[i] = c;
                ans.push_back(s);
            }
        } else {
            for (const auto& v : rotated) {
                s[i] = v[0];
                s[j] = v[1];
                find(n, i + 1, s, ans);
            }
        }
    }
    
public:
    vector<string> findStrobogrammatic(int n) {
        if (n == 0) return {};
        if (n == 1) return {"0", "1", "8"};
        
        vector<string> ans;
        string s(n, '#');
        for (int i = 1; i < rotated.size(); ++i) {
            s[0] = rotated[i][0];
            s[n - 1] = rotated[i][1];
            find(n, 1, s, ans);
        }
        return ans;
    }
};