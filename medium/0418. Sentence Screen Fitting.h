// 418. Sentence Screen Fitting
// https://leetcode.com/problems/sentence-screen-fitting/

class Solution {
    struct Sentence {
        int endRow; // last char of last word
        int endCol;
    };
    
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        const int M = cols - (int)sentence[0].length() + 1;
        if (M <= 0) return 0;
        // sentence start from c
        vector<Sentence> dp(M);
        
        const int N = sentence.size();
        
        for (int c = 0; c < M; ++c) {
            dp[c].endRow = 0;
            dp[c].endCol = c + sentence[0].length() - 1;
            for (int i = 1; i < N; ++i) {
                const int L = sentence[i].length();
                if (dp[c].endCol + 1 + L >= cols) {
                    dp[c].endRow += 1;
                    dp[c].endCol = L - 1;
                } else {
                    dp[c].endCol += L + 1;
                }
            }
        }
        
        const int L = dp[0].endRow * cols + dp[0].endCol + 1;
        int ans = 0, r = 0, c = 0;
        while (r + dp[c].endRow < rows) {
            ans += 1;
            r += dp[c].endRow;
            c = dp[c].endCol;
            
            int remain = cols - c;
            int cnt = remain / (L + 1);
            if (cnt > 0) {
                ans += cnt;
                c += L + cnt * (L + 1);
            }
            
            // append a space for next sentence
            c += 2;

            if (c >= M) {
                r += 1;
                c = 0;
            }
        }
        return ans;
    }
};