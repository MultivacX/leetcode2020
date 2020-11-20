// 483. Smallest Good Base
// https://leetcode.com/problems/smallest-good-base/

class Solution {
public:
    string smallestGoodBase(string n) {
        // n = [3, 10^18].
        const int64_t N = stoll(n);
        // ans = (minBase, maxBase]
        int64_t minBase = 1;     // 1^0 + 1^1 + ... + 1^N
        int64_t maxBase = N - 1; // 11
        // cnt(1) = [2, N)
        int64_t min1cnt = 2; // 11                    -> base : N - 1
        int64_t max1cnt = N; // 1^0 + 1^1 + ... + 1^N -> base : 1
        while (min1cnt < max1cnt) {
            int64_t cnt = min1cnt + (max1cnt - min1cnt) / 2;
            while (minBase < maxBase) {
            
            }
        }
        
        return "";
    }
};