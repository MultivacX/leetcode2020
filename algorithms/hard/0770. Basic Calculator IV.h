// 770. Basic Calculator IV
// https://leetcode.com/problems/basic-calculator-iv/

class Solution {
    // cof * v[0] * ... * v[n-1]
    struct Var {
        int cof = 1;
        vector<string> v;
    };
    
    // num + Var[0] + ... + Var[n-1]
    struct Exp {
        int num = 0;
        vector<Var> vars;
    };
    
    unordered_map<string, int> m;
    
    int getNum(const string& e, int& i) {
        int num = 0;
        while (i < e.length() && isdigit(e[i])) 
            num = num * 10 + e[i++] - '0';
        return num;
    }
    
    string getVar(const string& e, int& i) {
        string var;
        while (i < e.length() && isalpha(e[i])) 
            var += e[i++];
        return var;
    }
    
    Exp calc(const string& e, int& i) {
        vector<Exp> exps;
        int opt = 0;
        
        while (i < e.length() && e[i] != ')') {
            if (e[i] == ' ') { ++i; continue; }
            
            if (e[i] == '(') {
                ++i;
                auto t = calc(e, i);
                ++i;
            }
        }
        
        return exps.front();
    }
    
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        for (int i = 0; i < evalvars.size(); ++i)
            m.emplace(evalvars[i], evalints[i]);
        return {};
    }
};