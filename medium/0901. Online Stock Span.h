// 901. Online Stock Span

// Runtime: 420 ms, faster than 19.47% of C++ online submissions for Online Stock Span.
// Memory Usage: 84.2 MB, less than 7.69% of C++ online submissions for Online Stock Span.

// Time Complexity: O(count(stocks)).
// Space Complexity: O(count(stocks)).

class StockSpanner {
    // {price, span}
    stack<pair<int, int>> s;
    
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while (!s.empty() && s.top().first <= price) {
            span += s.top().second;
            s.pop();
        }
        s.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */