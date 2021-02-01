// 838. Push Dominoes

// Runtime: 20 ms, faster than 94.95% of C++ online submissions for Push Dominoes.
// Memory Usage: 9.4 MB, less than 100.00% of C++ online submissions for Push Dominoes.

class Solution {
public:
    string pushDominoes(string dominoes) {
        const int N = dominoes.length();
        int i = 0;
        while (i < N) {
            if (dominoes[i] == '.') {
                int l = i;
                ++i;
                while (i < N && dominoes[i] == '.') 
                    ++i;
                if (i == N) {
                    if (l > 0 && dominoes[l - 1] == 'R') {
                        while (l < N) dominoes[l++] = 'R';
                    }
                } else {
                    // [l-1]   [l] ...  [i]
                    // L/R/X   .......  L/R
                    if ((l == 0 || dominoes[l - 1] == 'L') && dominoes[i] == 'L') {
                        // L/X ... L
                        while (l < i) dominoes[l++] = 'L';
                    } else if (l > 0 && dominoes[l - 1] == 'R') {
                        if (dominoes[i] == 'L') {
                            // R ... L
                            int r = i - 1;
                            while (l < r) {
                                dominoes[l++] = 'R';
                                dominoes[r--] = 'L';
                            }
                        } else {
                            // R ... R
                            while (l < i) dominoes[l++] = 'R';
                        }
                    }
                }
            } else {
                ++i;
            }
        }
        return dominoes;
    }
};