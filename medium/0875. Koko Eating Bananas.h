// 875. Koko Eating Bananas
// https://leetcode.com/problems/koko-eating-bananas/

// Runtime: 76 ms, faster than 79.09% of C++ online submissions for Koko Eating Bananas.
// Memory Usage: 19.1 MB, less than 32.23% of C++ online submissions for Koko Eating Bananas.
    
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1;//*min_element(begin(piles), end(piles));
        int r = *max_element(begin(piles), end(piles)) + 1;
        int ans = r;
        while (l < r) {
            int k = l + (r - l) / 2;
            int h = 0;
            for (int i : piles) h += i / k + (i % k ? 1 : 0);
            if (h <= H) ans = min(ans, k);
            if (h > H) l = k + 1;
            else r = k;
        }
        return ans;
    }
};