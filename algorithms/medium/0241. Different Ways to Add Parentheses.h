// 241. Different Ways to Add Parentheses

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Different Ways to Add Parentheses.
// Memory Usage: 10.3 MB, less than 83.33% of C++ online submissions for Different Ways to Add Parentheses.

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if (input.empty()) return {};
        return computer(input);
    }
    
    unordered_map<string, vector<int>> m;
    
    vector<int>& computer(string input) {
        auto it = m.find(input);
        if (it != m.end()) 
            return m[input];
        
        vector<int> ans;
        for (int i = 0; i < input.length(); ++i) {
            if (input[i] == '+') {
                vector<int>& left = computer(input.substr(0, i));
                vector<int>& right = computer(input.substr(i + 1)); 
                for (int l : left) for (int r : right) ans.push_back(l + r);
            } else if (input[i] == '-') {
                vector<int>& left = computer(input.substr(0, i));
                vector<int>& right = computer(input.substr(i + 1)); 
                for (int l : left) for (int r : right) ans.push_back(l - r);
            } else if (input[i] == '*') {
                vector<int>& left = computer(input.substr(0, i));
                vector<int>& right = computer(input.substr(i + 1)); 
                for (int l : left) for (int r : right) ans.push_back(l * r);
            }
        }
        if (ans.empty()) ans.push_back(stoi(input));
        m[input] = ans;
        return m[input];
    }
};