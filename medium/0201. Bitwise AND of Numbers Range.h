// 201. Bitwise AND of Numbers Range

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == n) return m;
        
        int ans = 0;
        int position = 30;
        while (m > 0 && m < n) {
            while (position >= 0) {
                int bit = 1 << position;
                --position;
                
                if ((n & bit) == 0) 
                    continue;
                
                // cout << " " << endl;
                // cout << "m   : " << bitset<32>(m) << endl;
                // cout << "n   : " << bitset<32>(n) << endl;
                // cout << "bit : " << bitset<32>(bit) << endl;
                
                int mask = position >= 0 ? (1 << position) - 1 : 0;
                // cout << "mask: " << bitset<32>(mask) << endl;
                if ((m & bit) == 0) {
                    n = 0;
                    break;
                } else {
                    n &= 0;
                    m &= 0;
                    ans |= bit;
                }
            }
        }
        return ans;
    }
};