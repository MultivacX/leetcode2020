// 1995. Count Special Quadruplets
// https://leetcode.com/problems/count-special-quadruplets/

// Runtime: 20 ms, faster than 98.83% of C++ online submissions for Count Special Quadruplets.
// Memory Usage: 10.4 MB, less than 95.79% of C++ online submissions for Count Special Quadruplets.
    
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        array<int, 101> m{0};
        for (int i : nums) 
            ++m[i];
        
        int k = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int d = nums[i];
            --m[d];
            
            // d = t + t + t
            int t = d / 3;
            if (d == t * 3 && m[t] >= 3) 
                k += m[t] * (m[t] - 1) * (m[t] - 2) / 6;
            
            // d = t + t + r
            for (int t = 1; t * 2 < d; ++t) {
                int r = d - t * 2;
                if (t != r && m[t] >= 2 && m[r])
                    k += m[t] * (m[t] - 1) / 2 * m[r];
            }
            
            int a = 1, b = 2, c = 3;
            while (a + b + c <= d) {
                while (a + b + c <= d && m[a]) {    
                    while (a + b + c <= d && m[b]) {
                        if (a + b + c == d && m[c]) {
                            k += m[a] * m[b] * m[c];
                        }
                        ++c;
                    }   
                    ++b;
                    c = b + 1;
                }
                ++a;
                b = a + 1;
                c = b + 1;
            }
        }
        return k;
    }
};