// 616. Add Bold Tag in String
// https://leetcode.com/problems/add-bold-tag-in-string/

// Runtime: 16 ms, faster than 98.07% of C++ online submissions for Add Bold Tag in String.
// Memory Usage: 10.1 MB, less than 92.12% of C++ online submissions for Add Bold Tag in String.
    
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        const int N = s.length();
        vector<bool> marks(N, false);
        for (string& str : dict) {
            int i = s.find(str, 0);
            while (i != string::npos) {
                for (int j = i; j < i + str.length(); ++j)
                    marks[j] = true;
                i = s.find(str, i + 1);
            }
        }
        string ans;
        for (int i = 0, k = 0; i < N; ++i) {
            if (marks[i] && k == 0) { k = 1; ans += "<b>"; }
            ans += s[i];
            if ((i + 1 == N || !marks[i + 1]) && k == 1) { k = 0; ans += "</b>"; }
        }
        return ans;
    }
};