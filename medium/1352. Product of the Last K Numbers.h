// 1352. Product of the Last K Numbers

// Runtime: 304 ms, faster than 45.49% of C++ online submissions for Product of the Last K Numbers.
// Memory Usage: 60.3 MB, less than 100.00% of C++ online submissions for Product of the Last K Numbers.

class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (products.empty() || products.back() == 0 || num == 0) {
            products.push_back(num);
        } else {
            products.push_back(products.back() * num);
        }
        
        if (num == 0) zero_idx.push_back(products.size() - 1);
    }
    
    int getProduct(int k) {
        const int n = products.size();
        if (n == 0) return 0;
        
        int i = max(n - k, 0);
        int j = n - 1;
        // nums[i] * ... * nums[j]
        
        // i <= *it
        auto it = lower_bound(begin(zero_idx), end(zero_idx), i);
        if (it != end(zero_idx)) return 0;
        
        return (i == 0 || products[i - 1] == 0) ? products[j] : products[j] / products[i - 1];
    }
    
    vector<int> products;
    vector<int> zero_idx;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */