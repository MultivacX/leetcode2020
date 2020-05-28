// 1423. Maximum Points You Can Obtain from Cards

// Runtime: 128 ms, faster than 97.80% of C++ online submissions for Maximum Points You Can Obtain from Cards.
// Memory Usage: 42.6 MB, less than 100.00% of C++ online submissions for Maximum Points You Can Obtain from Cards.

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int score = accumulate(begin(cardPoints), begin(cardPoints) + k, 0);
        int ans = score;
        
        const int N = cardPoints.size();
        int i = k - 1;
        int j = N - 1;
        while (i != j && i >= 0 && j >= 0 && j >= N - k) {
            score = score - cardPoints[i--] + cardPoints[j--];
            ans = max(ans, score);
        }
        
        return ans;
    }
};