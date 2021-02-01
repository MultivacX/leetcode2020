// 758. Bold Words in String
// https://leetcode.com/problems/bold-words-in-string/

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Bold Words in String.
// Memory Usage: 8.6 MB, less than 60.00% of C++ online submissions for Bold Words in String.
    
class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        string T(S);
        for (const auto& w : words) {
            int i = S.find(w);
            while (i != string::npos) {
                for (int j = 0; j < w.length(); ++j)
                    T[i + j] = S[i + j] - 'a' + 'A';
                i = S.find(w, i + 1);
            }
        }
        const int N = S.length();
        string s;
        for (int i = 0, b = 0; i < N; ++i) {
            if ('a' <= T[i] && T[i] <= 'z') {
                if (b) s += "</b>";
                b = 0;
            } else if (b == 0) {
                b = 1;
                s += "<b>";
            }
            
            s += S[i];
            if (i + 1 == N && b)
                s += "</b>";
        }
        return s;
    }
};