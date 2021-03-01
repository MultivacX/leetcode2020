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


class Solution {
public:
    int totalFruit(vector<int>& tree) {
        const int n = tree.size();
        int ans = 1;
        int type1 = -1, cnt1 = 0;
        int type2 = tree[0], cnt2 = 0;
        int i = 0;
        while (i < n) {
            if (tree[i] == type2) {
                ++cnt2;
            } else if (tree[i] == type1 || -1 == type1) {
                type1 = tree[i];
                ++cnt1;
            } else {
                ans = max(ans, cnt1 + cnt2);
                int j = i - 1;
                type1 = tree[j];
                cnt1 = 0;
                while (tree[j] == type1) {
                    ++cnt1;
                    --j;
                }
                type2 = tree[i];
                cnt2 = 1;
            }
            ++i;
        }
        return max(ans, cnt1 + cnt2);
    }
};