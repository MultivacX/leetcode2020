// 518. Coin Change 2

// Runtime: 72 ms, faster than 12.21% of C++ online submissions for Coin Change 2.
// Memory Usage: 22.2 MB, less than 14.29% of C++ online submissions for Coin Change 2.

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (coins.empty()) return amount == 0 ? 1 : 0;
        sort(coins.begin(), coins.end());
        vector<vector<int>> counts(amount + 1, vector<int>(coins.size(), -1));
        return change(amount, coins, 0, counts);
    }
    
    int change(int amount, const vector<int>& coins, int idx, vector<vector<int>>& counts) {
        if (amount == 0) return 1;
        if (idx >= coins.size()) return 0;
        if (counts[amount][idx] >= 0) return counts[amount][idx];
        
        counts[amount][idx] = 0;
        for (int i = idx; i < coins.size() && amount >= coins[i]; ++i) {
            counts[amount][idx] += change(amount - coins[i], coins, i, counts);
        }
        return counts[amount][idx];
    }
};