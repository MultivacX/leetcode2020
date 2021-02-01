// 483. Smallest Good Base
// https://leetcode.com/problems/smallest-good-base/

class Solution {
public:
    string smallestGoodBase(string n) {
        // n = [3, 10^18].
        const int64_t N = stoll(n);
        
        // k^0 + k^1 + ... + k^n -> base k
        // N = (1 - k^(n+1)) / (1 - k)

        // ans = (minBase, maxBase]
        int64_t minBase = 1;     
        int64_t maxBase = N - 1;
        // cnt(1) = [2, N)
        int64_t min1cnt = 2; 
        int64_t max1cnt = N; 
        while (min1cnt < max1cnt) {
            int64_t cnt = min1cnt + (max1cnt - min1cnt) / 2;
            while (minBase < maxBase) {
            
            }
        }
        
        return "";
    }
};