// 1561. Maximum Number of Coins You Can Get
// https://leetcode.com/problems/maximum-number-of-coins-you-can-get/

// Runtime: 312 ms, faster than 98.55% of C++ online submissions for Maximum Number of Coins You Can Get.
// Memory Usage: 53.7 MB, less than 5.96% of C++ online submissions for Maximum Number of Coins You Can Get.

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        const int N = piles.size();
        sort(begin(piles), end(piles));
        int coins = 0;
        for (int i = N / 3; i < N; i += 2)
            coins += piles[i];
        return coins;
    }
};