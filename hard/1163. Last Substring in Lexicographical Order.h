// 1163. Last Substring in Lexicographical Order
// https://leetcode.com/problems/last-substring-in-lexicographical-order/

// Runtime: 64 ms, faster than 35.93% of C++ online submissions for Last Substring in Lexicographical Order.
// Memory Usage: 22.2 MB, less than 9.26% of C++ online submissions for Last Substring in Lexicographical Order.

class Solution {
public:
    string lastSubstring(string s) {
        const int N = s.length();
        
        string t; 
        char c = ' ';
        vector<int> v;
        for (int i = 0; i < N; ++i) {
            if (s[i] > c) {
                c = s[i];
                v.clear();
                v.push_back(i + 1);
            } else if (s[i] == c) {
                v.push_back(i + 1);
            }
        }
        t += c;
        while (!v.empty()) {
            if (v.back() - v.front() + 1 == v.size())
                return t + s.substr(v.front());
            char c = ' ';
            vector<int> tmp;
            for (int i : v) {
                if (i >= N) continue;
                if (s[i] > c) {
                    c = s[i];
                    tmp.clear();
                    tmp.push_back(i + 1);
                } else if (s[i] == c) {
                    tmp.push_back(i + 1);
                }
            }
            if (c != ' ') t += c;
            v = tmp;
        }
        return t;
    }
};