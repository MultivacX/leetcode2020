// 1357. Apply Discount Every n Orders
// https://leetcode.com/problems/apply-discount-every-n-orders/

// Runtime: 348 ms, faster than 26.38% of C++ online submissions for Apply Discount Every n Orders.
// Memory Usage: 120.6 MB, less than 11.06% of C++ online submissions for Apply Discount Every n Orders.

class Cashier {
    int n_; 
    int discount_; 
    unordered_map<int, int> m_;
    int cnt_;
    
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        n_ = n;
        discount_ = discount;
        for (int i = 0; i < products.size(); ++i)
            m_.insert({products[i], prices[i]});
        cnt_ = 0;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        int discount = ++cnt_ == n_ ? discount_ : 0;
        if (cnt_ == n_) cnt_ = 0;
        
        double ans = 0;
        for (int i = 0; i < product.size(); ++i) {
            int x = m_[product[i]] * amount[i];
            ans += x - discount * x / 100.0;
        }
        return ans;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */