// 475. Heaters

// Runtime: 84 ms, faster than 51.48% of C++ online submissions for Heaters.
// Memory Usage: 11.3 MB, less than 28.57% of C++ online submissions for Heaters.

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        const int m = houses.size();
        if (m == 0) return 0;
        const int n = heaters.size();
        if (n == 0) return INT_MAX;
        
        sort(begin(houses), end(houses));
        sort(begin(heaters), end(heaters));
        
        vector<int> l(m, INT_MAX);
        int j = 0;
        for (int i = 0; i < m && j < n; ++i) {
            while (j + 1 < n && heaters[j + 1] <= houses[i]) ++j;
            if (heaters[j] <= houses[i]) l[i] = houses[i] - heaters[j];
        }
        
        vector<int> r(m, INT_MAX);
        j = n - 1;
        for (int i = m - 1; i >= 0 && j >= 0; --i) {
            while (j - 1 >= 0 && heaters[j - 1] >= houses[i]) --j;
            if (heaters[j] >= houses[i]) r[i] = heaters[j] - houses[i];
        }
        
        int ans = INT_MIN;
        for (int i = 0; i < m; ++i) {
            // printf("%d>%d<%d\n", l[i], houses[i], r[i]);
            ans = max(ans, min(l[i], r[i]));
        }
        
        return ans;
    }
};