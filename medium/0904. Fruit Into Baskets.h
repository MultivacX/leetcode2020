// 904. Fruit Into Baskets
// https://leetcode.com/problems/fruit-into-baskets/

// Runtime: 176 ms, faster than 95.47% of C++ online submissions for Fruit Into Baskets.
// Memory Usage: 56.7 MB, less than 5.05% of C++ online submissions for Fruit Into Baskets.

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int ans = 1;
        int t0 = tree[0];
        int t1 = -1;
        int cur = 1;
        for (int i = 1; i < tree.size(); ++i) {
            if (t0 == tree[i] || t1 == tree[i]) ++cur;
            else if (t1 < 0) { t1 = tree[i]; ++cur; }
            else {
                ans = max(ans, cur);
                
                int j = i - 1;
                if (t0 == tree[j]) t1 = tree[i];
                else t0 = tree[i];
                
                cur = 2;
                while (j - 1 >= 0 && tree[j - 1] == tree[j]) 
                    ++cur, --j;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};