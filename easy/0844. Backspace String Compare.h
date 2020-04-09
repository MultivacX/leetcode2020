// 844. Backspace String Compare

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Backspace String Compare.
// Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for Backspace String Compare.

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int ls = backspace(S);
        int lt = backspace(T);
        cout << S << endl;
        cout << T << endl;
        if (ls != lt) return false;
        if (ls == 0) return true;
        
        const int M = S.length();
        const int N = T.length();
        int i = 0;
        int j = 0;
        while (i < M && j < N) {
            cout << S[i] << "  " << T[j] << endl;
            if (S[i] == '#') ++i;
            else if (T[j] == '#') ++j;
            else if (S[i] != T[j]) return false;
            else {
                ++i;
                ++j;
            }
        }
        return true;
    }
    
    int backspace(string& s) {
        const int N = s.length();
        int ans = 0;
        int cnt = 0;
        for (int i = N - 1; i >= 0; --i) {
            if (s[i] == '#') ++cnt;
            else if (cnt > 0) {
                s[i] = '#';
                --cnt;
            }
            else ++ans;
        }
        return ans;
    }
};