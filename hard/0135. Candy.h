// 135. Candy
// https://leetcode.com/problems/candy/

// Runtime: 40 ms, faster than 67.24% of C++ online submissions for Candy.
// Memory Usage: 18.1 MB, less than 5.95% of C++ online submissions for Candy.

class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();
        vector<int> candies(N, 1);
        for (int i = 1; i < N; ++i) {
            if (ratings[i - 1] < ratings[i] && candies[i - 1] >= candies[i]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = N - 2; i >= 0; --i) {
            if (ratings[i + 1] < ratings[i] && candies[i + 1] >= candies[i]) {
                candies[i] = candies[i + 1] + 1;
            }
        }
        return accumulate(begin(candies), end(candies), 0);
    }
};