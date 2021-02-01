// 605. Can Place Flowers

// Runtime: 56 ms, faster than 6.90% of C++ online submissions for Can Place Flowers.
// Memory Usage: 20.5 MB, less than 6.67% of C++ online submissions for Can Place Flowers.

// Time Complexity: O(N).
// Space Complexity: O(1).

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        const int N = flowerbed.size();
        for (int i = 0; i < N; ++i) {
            if (flowerbed[i] == 1) continue;
            if ((i == 0 || flowerbed[i - 1] == 0) && (i + 1 >= N || flowerbed[i + 1] == 0)) {
                // cout << i << endl;
                // flowerbed[i] = 1; 
                ++i;
                --n;
                if (n == 0) return true;
            }
        }
        return n == 0;
    }
};