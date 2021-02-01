// 1742. Maximum Number of Balls in a Box
// https://leetcode.com/problems/maximum-number-of-balls-in-a-box/

// Runtime: 8 ms, faster than 87.50% of C++ online submissions for Maximum Number of Balls in a Box.
// Memory Usage: 6 MB, less than 87.50% of C++ online submissions for Maximum Number of Balls in a Box.
    
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> m(46, 0);
        int ans = 0;
        for (int i = lowLimit; i <= highLimit; ++i) {
            int k = i;
            int v = 0;
            while (k > 0) {
                v += k % 10;
                k /= 10;
            }
            if (++m[v] > ans)
                ans = m[v];
        }
        return ans;
    }
};