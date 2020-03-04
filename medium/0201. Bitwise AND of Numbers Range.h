// 201. Bitwise AND of Numbers Range

// Runtime: 24 ms, faster than 19.27% of C++ online submissions for Bitwise AND of Numbers Range.
// Memory Usage: 7.2 MB, less than 100.00% of C++ online submissions for Bitwise AND of Numbers Range.

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m >= n - 1) return m & n;
        
        int ans = 0;
        int y = 0;
        for (int i = 30; i >= 0; --i) {
            int bit = 1 << i;
            if ((m & bit) == 0 || (n & bit) == 0) {
                if (n & bit)
                    y |= bit;
                continue;
            }
            
            int x = y | (bit - 1);
            // cout << "" << endl;
            // cout << "y: " << bitset<32>(y) << endl;
            // cout << "   " << bitset<32>(bit - 1) << endl;
            // cout << "m: " << bitset<32>(m) << endl;
            // cout << "x: " << bitset<32>(x) << endl;
            // cout << "n: " << bitset<32>(n) << endl;
            if (x <= m || x >= n)
                ans |= bit;
            
            y |= bit;
        }
        return ans;
    }
};