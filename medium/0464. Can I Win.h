// 464. Can I Win

// Runtime: 92 ms, faster than 65.31% of C++ online submissions for Can I Win.
// Memory Usage: 20.4 MB, less than 100.00% of C++ online submissions for Can I Win.

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (1 + maxChoosableInteger) * maxChoosableInteger >> 1;
        return sum >= desiredTotal && canIWin(maxChoosableInteger, desiredTotal, 0);
    }
    
    unordered_map<int, bool> m;
    
    bool canIWin(int maxChoosableInteger, int desiredTotal, int used) {
        for (int i = maxChoosableInteger; i > 0; --i) {
            if ((1 << i) & used) continue;
            if (i >= desiredTotal) return true;
            
            used |= 1 << i;
            if (!m.count(used)) m[used] = !canIWin(maxChoosableInteger, desiredTotal - i, used);
            if (m[used]) return true;
            used &= ~(1 << i);
        }
        return false;
    }
};