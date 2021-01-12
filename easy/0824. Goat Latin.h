// 824. Goat Latin
// https://leetcode.com/problems/goat-latin/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Goat Latin.
// Memory Usage: 6.8 MB, less than 80.24% of C++ online submissions for Goat Latin.
    
class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
public:
    string toGoatLatin(string S) {
        const int N = S.length();
        string T;
        bool wordStart = true;
        char first = ' ';
        int j = 1;
        for (int i = 0; i < N; ++i) {
            if (S[i] == ' ') {
                if (!isVowel(first))
                    T += first;
                T += "ma" + string(j, 'a') += S[i];
                wordStart = true;
                ++j;
            } else if (wordStart) {
                wordStart = false;
                first = S[i];
                if (isVowel(first))
                    T += S[i];
            } else {
                T += S[i];
            }
        }
        if (!wordStart) {
            if (!isVowel(first))
                T += first;
            T += "ma" + string(j, 'a');
        }
        return T;
    }
};