// 282. Expression Add Operators

// Runtime: 416 ms, faster than 74.98% of C++ online submissions for Expression Add Operators.
// Memory Usage: 17.8 MB, less than 83.33% of C++ online submissions for Expression Add Operators.

class Solution {
public:
    vector<string> addOperators(string num, int target) {        
        const int N = num.length();
        vector<string> ans;
        vector<string> exp;
        for (int i = 1; i <= N - 1; ++i) {
            string A(num.substr(0, i));
            auto a = stoll(A);
            
            for (int j = 1; i + j <= N; ++j) {
                string B(num.substr(i, j));
                auto b = stoll(B);                
                
                exp.emplace_back(A + "+" + B);
                opt(num, target, i + j, a + b, b, exp, ans);
                exp.pop_back();
                
                exp.emplace_back(A + "-" + B);
                opt(num, target, i + j, a - b, -b, exp, ans);
                exp.pop_back();
                
                exp.emplace_back(A + "*" + B);
                opt(num, target, i + j, a * b, a * b, exp, ans);
                exp.pop_back();
                
                // no leading zero
                if (num[i] == '0') break;
            }
            
            // no leading zero
            if (num[0] == '0') break;
        }
        if (N > 0 && num == to_string(target)) ans.emplace_back(num);
        return ans;
    }
    
    void opt(const string& num, long long target, int idx, long long val, long long diff, vector<string>& exp, vector<string>& ans) {
        const int N = num.length();
        if (idx >= N) {
            // for (const string& s : exp) cout << s; cout << endl;
            if (target == val) 
                ans.emplace_back(accumulate(begin(exp), end(exp), string{}));
            return;
        }
        
        for (int i = 1; idx + i <= N; ++i) {
            string C(num.substr(idx, i));
            auto c = stoll(C);
            
            exp.emplace_back("+" + C);
            opt(num, target, idx + i, val + c, c, exp, ans);
            exp.pop_back();
            
            exp.emplace_back("-" + C);
            opt(num, target, idx + i, val - c, -c, exp, ans);
            exp.pop_back();
            
            exp.emplace_back("*" + C);
            opt(num, target, idx + i, (val - diff) + diff * c, diff * c, exp, ans);
            exp.pop_back();
            
            // no leading zero
            if (num[idx] == '0') break;
        }
    }
};