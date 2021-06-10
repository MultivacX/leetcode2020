// 1891. Cutting Ribbons
// https://leetcode.com/problems/cutting-ribbons/

// Runtime: 180 ms, faster than 100.00% of C++ online submissions for Cutting Ribbons.
// Memory Usage: 92.4 MB, less than 100.00% of C++ online submissions for Cutting Ribbons.
    
class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int l = 1, r = 100001, ans = 0;
        while (l < r) {
            int m = l + (r - l) / 2, i = 0;
            for (int j : ribbons) i += j / m;
            if (i >= k) ans = max(ans, m);
            
            if (i < k) r = m;
            else l = m + 1;
        }
        return ans;
    }
};