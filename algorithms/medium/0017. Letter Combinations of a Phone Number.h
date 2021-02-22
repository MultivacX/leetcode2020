// 17. Letter Combinations of a Phone Number

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static const unordered_map<char, string> m{
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"},
        };
        
        if (digits.empty()) return {};
        vector<string> ans;
        string num;
        comb(m, digits, ans, 0, num);
        return ans;
    }
    
    void comb(const unordered_map<char, string>& m, const string& digits, vector<string>& ans, int i, string& num) {
        if (i >= digits.length()) {
            ans.push_back(num);
            return;
        }
        
        if (m.count(digits[i]) == 0) return;
        
        for (const char& c : m.at(digits[i])) {
            num.push_back(c);
            comb(m, digits, ans, i + 1, num);
            num.pop_back();
        }
    }
};


class Solution {
    string s;
    vector<string> ans;
    
    void comb(const string& digits, int i) {
        static unordered_map<char, string> m{
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };
        
        if (i >= digits.length()) {
            if (!s.empty()) ans.push_back(s);
            return;
        }
        
        for (char d : m[digits[i]]) {
            s.push_back(d);
            comb(digits, i + 1);
            s.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        comb(digits, 0);
        return ans;
    }
};