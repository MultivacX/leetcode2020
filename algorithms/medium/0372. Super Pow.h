// 372. Super Pow

// Runtime: 16 ms, faster than 44.96% of C++ online submissions for Super Pow.
// Memory Usage: 10.4 MB, less than 20.00% of C++ online submissions for Super Pow.

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (a == 1) return 1;
        if (b.empty()) return 1;
        
        int ans = 1;
        for (int i = 0; i < b.back(); ++i) {
            ans = (ans % 1337) * (a % 1337) % 1337;
        }
        b.pop_back();
        if (!b.empty()) {
            int c = superPow(a, b);
            for (int i = 0; i < 10; ++i) {
                ans = (ans % 1337) * (c % 1337) % 1337;
            }
        }
        return ans;
    }
};