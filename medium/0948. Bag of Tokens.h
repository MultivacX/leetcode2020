// 948. Bag of Tokens
// https://leetcode.com/problems/bag-of-tokens/

// Runtime: 12 ms, faster than 84.96% of C++ online submissions for Bag of Tokens.
// Memory Usage: 11.1 MB, less than 99.21% of C++ online submissions for Bag of Tokens.

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        const int N = tokens.size();
        sort(begin(tokens), end(tokens));
        int ans = 0;
        int score = 0;
        int i = 0;
        int j = N - 1;
        while (i <= j) {
            if (tokens[i] <= P) {
                P -= tokens[i++];
                ++score;
                ans = max(ans, score);
            } else if (score > 0) {
                P += tokens[j--];
                --score;
            } else break;
        }
        return ans;
    }
};