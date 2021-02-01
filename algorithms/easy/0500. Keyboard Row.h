// 500. Keyboard Row
// https://leetcode.com/problems/keyboard-row/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Keyboard Row.
// Memory Usage: 7.2 MB, less than 62.95% of C++ online submissions for Keyboard Row.
    
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // static const string K1 = "QWERTYUIOP";
        // static const string K2 = "ASDFGHJKL";
        // static const string K3 = "ZXCVBNM";
        // for (auto c : K1) cout << "{\'" << c << "\', 1}, " << "{\'" << (char)tolower(c) << "\', 1}, "; cout << endl;
        // for (auto c : K2) cout << "{\'" << c << "\', 2}, " << "{\'" << (char)tolower(c) << "\', 2}, "; cout << endl;
        // for (auto c : K3) cout << "{\'" << c << "\', 3}, " << "{\'" << (char)tolower(c) << "\', 3}, "; cout << endl;
        
        static unordered_map<char, int> m{
            {'Q', 1}, {'q', 1}, {'W', 1}, {'w', 1}, {'E', 1}, {'e', 1}, {'R', 1}, {'r', 1}, {'T', 1}, {'t', 1}, {'Y', 1}, {'y', 1}, {'U', 1}, {'u', 1}, {'I', 1}, {'i', 1}, {'O', 1}, {'o', 1}, {'P', 1}, {'p', 1}, 
{'A', 2}, {'a', 2}, {'S', 2}, {'s', 2}, {'D', 2}, {'d', 2}, {'F', 2}, {'f', 2}, {'G', 2}, {'g', 2}, {'H', 2}, {'h', 2}, {'J', 2}, {'j', 2}, {'K', 2}, {'k', 2}, {'L', 2}, {'l', 2}, 
{'Z', 3}, {'z', 3}, {'X', 3}, {'x', 3}, {'C', 3}, {'c', 3}, {'V', 3}, {'v', 3}, {'B', 3}, {'b', 3}, {'N', 3}, {'n', 3}, {'M', 3}, {'m', 3}, 
        };
        
        vector<string> ans;
        for (const string& w : words) {
            int v = m[w[0]];
            int i = 1;
            for (; i < w.length() && v == m[w[i]]; ++i);
            if (i == w.length()) ans.push_back(w);
        }
        return ans;
    }
};

