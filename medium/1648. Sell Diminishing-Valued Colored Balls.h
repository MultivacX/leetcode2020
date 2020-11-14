// 1648. Sell Diminishing-Valued Colored Balls
// https://leetcode.com/problems/sell-diminishing-valued-colored-balls/

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        int64_t N = inventory.size();
        // {cnt, colors}
        map<int, int> m;
        int64_t K = 0;
        for (int i : inventory) ++m[i], K += i;
        
        int64_t v = 0;
        while (orders > 0) {
            // [1, r] [r+1, i]
            int64_t r = ceil((double)(K - orders) / N);

            N = 0;
            map<int, int> tmp;
            K = 0;
            
            for (auto it = m.rbegin(); it != m.rend(); ++it) {
                if (it->first < r) break;
                if (it->first == r) {

                } else {
                    
                }
            }
            m = tmp;
        }
        return v;
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