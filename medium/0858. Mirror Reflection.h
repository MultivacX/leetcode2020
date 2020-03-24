// 858. Mirror Reflection

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Mirror Reflection.
// Memory Usage: 5.8 MB, less than 100.00% of C++ online submissions for Mirror Reflection.

class Solution {
public:
    int mirrorReflection(int p, int q) {
        // i >= 0, j >= 0
        // 0 : (p, 0) + (i * 2p, j * 2p)
        // 1 : (p, p) + (i * 2p, j * 2p)
        // 2 : (0, p) + (i * 2p, j * 2p)
        
        // p * y = q * x
        
        if (0 == q) return 0;
        if (p == q) return 1;
        
        int r = std::gcd(p, q);
        
        int x = p / r % 2;
        int y = q / r % 2;
        if (x == y) return 1;
        if (y == 0) return 0;
        return 2;
    }
};