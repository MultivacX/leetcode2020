// 1801. Number of Orders in the Backlog
// https://leetcode.com/problems/number-of-orders-in-the-backlog/

// Runtime: 220 ms, faster than 82.51% of C++ online submissions for Number of Orders in the Backlog.
// Memory Usage: 58.6 MB, less than 85.25% of C++ online submissions for Number of Orders in the Backlog.
    
class Solution {
    struct order {
        order(int p, int a) : price(p), amount(a) {}
        int price;
        int amount;
    };
    
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        auto ge = [](const order& l, const order& r){
            return l.price < r.price;
        };
        priority_queue<order, vector<order>, decltype(ge)> buy(ge);
        
        auto le = [](const order& l, const order& r){
            return l.price > r.price;
        };
        priority_queue<order, vector<order>, decltype(le)> sell(le);

        // or use 2-map
        
        for (const auto& o : orders) {
            int price = o[0], amount = o[1], orderType = o[2];
            /*if (orderType == 0) {
                while (!sell.empty() && sell.top().price <= price) {
                    auto order = sell.top(); sell.pop();
                    if (order.amount <= amount) {
                        amount -= order.amount;
                    } else {
                        order.amount -= amount;
                        amount = 0;
                        sell.push(order);
                        break;
                    }
                }
                if (amount > 0) buy.emplace(price, amount);
            } else {
                while (!buy.empty() && buy.top().price >= price) {
                    auto order = buy.top(); buy.pop();
                    if (order.amount <= amount) {
                        amount -= order.amount;
                    } else {
                        order.amount -= amount;
                        amount = 0;
                        buy.push(order);
                        break;
                    }
                }
                if (amount > 0) sell.emplace(price, amount);
            }*/
            if (orderType == 0) buy.emplace(price, amount);
            else sell.emplace(price, amount);
            while (!buy.empty() && !sell.empty() && buy.top().price >= sell.top().price) {
                auto b = buy.top(); buy.pop();
                auto s = sell.top(); sell.pop();
                if (b.amount > s.amount) buy.emplace(b.price, b.amount - s.amount);
                else if (b.amount < s.amount) sell.emplace(s.price, s.amount - b.amount);
            }
        }
        
        int64_t ans = 0;
        while (!sell.empty()) { ans += sell.top().amount; sell.pop(); }
        while (!buy.empty()) { ans += buy.top().amount; buy.pop(); }
        return ans % 1000000007;
    }
};