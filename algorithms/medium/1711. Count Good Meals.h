// 1711. Count Good Meals
// https://leetcode.com/problems/count-good-meals/

// Runtime: 472 ms, faster than 80.00% of C++ online submissions for Count Good Meals.
// Memory Usage: 58.4 MB, less than 100.00% of C++ online submissions for Count Good Meals.
    
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> m;
        for (int i : deliciousness) ++m[i];
        
        int64_t ans = 0;
        while (!m.empty()) {
            int v1 = m.begin()->first;
            int64_t c1 = m.begin()->second;
            for (int b = 0; b < 31; ++b) {
                if ((1 << b) == v1) {
                    ans = (ans + c1 * (c1 - 1) / 2 % 1000000007) % 1000000007;
                    break;
                }
            }
            
            m.erase(m.begin());
            if (m.empty()) break;
            
            for (int b = 0; b < 31; ++b) {
                int v2 = (1 << b) - v1;
                if (m.count(v2) == 0) continue;
                int64_t c2 = m[v2];
                ans = (ans + c1 * c2 % 1000000007) % 1000000007;
            }
        }
        return ans;
    }
};