// 299. Bulls and Cows
// https://leetcode.com/problems/bulls-and-cows/

// Runtime: 4 ms, faster than 98.56% of C++ online submissions for Bulls and Cows.
// Memory Usage: 6.8 MB, less than 87.22% of C++ online submissions for Bulls and Cows.

class Solution {
public:
    string getHint(string secret, string guess) {
        const int N = secret.size();
        int A = 0;
        int B = 0;
        vector<int> b0(10, 0);
        vector<int> b1(10, 0);
        for (int i = 0; i < N; ++i) {
            if (secret[i] == guess[i]) ++A;
            else {
                ++b0[secret[i] - '0'];
                ++b1[guess[i] - '0'];
            }
        }
        for (int i = 0; i <= 9; ++i) B += min(b0[i], b1[i]);
        return to_string(A) + "A" + to_string(B) + "B";
    }
};