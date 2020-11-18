// 1648. Sell Diminishing-Valued Colored Balls
// https://leetcode.com/problems/sell-diminishing-valued-colored-balls/

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        int64_t TotalColors = inventory.size();
        // {cnt, colors}
        map<int64_t, int64_t> m;
        int64_t TotalBalls = 0;
        for (int i : inventory) ++m[i], TotalBalls += i;
        
        int64_t ans = 0;
        while (orders > 0) {
            int64_t cnt = m.rbegin().first;
            int64_t colors = m.rbegin().second;
            m.erase(cnt);

            // [1, left] [left+1, cnt]
            int64_t left = ceil((double)(TotalBalls - orders) / TotalColors);
            if (left == cnt) {
                int64_t sell = min(colors, orders);
                ans = (ans + cnt * sell) % 1000000007;
                orders -= sell;
                TotalBalls -= sell;
                if (cnt - 1 > 0) m[cnt - 1] += sell;
                if (colors - sell > 0) m[cnt] += colors - sell;
            } else if (left == 0) {
                ans = (ans + (1 + cnt) * cnt / 2 * colors) % 1000000007;
            } else {
                ans = (ans + (left + 1 + cnt) * (cnt - left) / 2 * colors) % 1000000007;
                m[left] += colors;
            }
        }
        return ans;
    }
};

// TLE
/*class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        const int64_t N = inventory.size();
        priority_queue<int> q(inventory.begin(), inventory.end());
        // int64_t k = accumulate(inventory.begin(), inventory.end(), (int64_t)0);
        int64_t v = 0;
        while (orders > 0) {
            int64_t n = orders / N;
            if (n == 0) n = 1;
            int64_t r = q.top(); q.pop();
            int64_t l = r - n + 1;
            // printf("[%d, %d] %d %d\n", l, r, n, orders);
            if (l > 1) q.push(l - 1);
            v = (v + (l + r) * n / 2) % 1000000007;
            orders -= n;
            // k -= n;
        }
        return v;
    }
};*/