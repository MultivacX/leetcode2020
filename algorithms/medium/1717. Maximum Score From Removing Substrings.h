// 1717. Maximum Score From Removing Substrings
// https://leetcode.com/problems/maximum-score-from-removing-substrings/

// Runtime: 128 ms, faster than 71.33% of C++ online submissions for Maximum Score From Removing Substrings.
// Memory Usage: 17.8 MB, less than 76.43% of C++ online submissions for Maximum Score From Removing Substrings.
    
class Solution {
    int getScore(const string& s, int x, int y, string XY) {
        int score = 0;
        string t;
        for (char c : s) {
            if (!t.empty() && t.back() == XY[0] && c == XY[1]) {
                score += x;
                t.pop_back();
            } else {
                t.push_back(c);
            }
        }
        swap(XY[0], XY[1]);
        int i = t.find(XY);
        if (i != string::npos) {
            score += y;
            int j = 1;
            while (i - j >= 0 && i + j + 1 < t.length() && t[i - j] == XY[0] && t[i + j + 1] == XY[1]) {
                score += y;
                ++j;
            }
            j = 2;
            while (i + j + 1 < t.length() && t[i + j] == XY[0] && t[i + j + 1] == XY[1]) {
                score += y;
                j += 2;
            }
        }
        return score;
    }
    
public:
    int maximumGain(string s, int x, int y) {
        string XY = "ab";
        if (x < y) swap(x, y), swap(XY[0], XY[1]);
        
        int score = 0;
        string t;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'a' || s[i] == 'b') 
                t += s[i];
            if ((s[i] != 'a' && s[i] != 'b') || i + 1 == s.length()) {
                score += getScore(t, x, y, XY);
                t = "";
            }
        }
        return score;
    }
};