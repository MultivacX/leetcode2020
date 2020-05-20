// 848. Shifting Letters

// Runtime: 80 ms, faster than 37.92% of C++ online submissions for Shifting Letters.
// Memory Usage: 20 MB, less than 25.00% of C++ online submissions for Shifting Letters.

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        const int N = S.length();
        int i = N - 1;
        int shift = shifts[i];
        S[i] = (S[i] - 'a' + shift) % 26 + 'a';
        for (i = N - 2; i >= 0; --i) {
            shift = (shift + shifts[i]) % 26;
            S[i] = (S[i] - 'a' + shift) % 26 + 'a';
        }
        return S;
    }
};