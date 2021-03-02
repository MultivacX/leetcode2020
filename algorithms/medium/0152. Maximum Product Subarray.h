// 152. Maximum Product Subarray

// Runtime: 4 ms, faster than 89.31% of C++ online submissions for Maximum Product Subarray.
// Memory Usage: 9.2 MB, less than 50.00% of C++ online submissions for Maximum Product Subarray.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int _max = nums[0];
        int _min = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; ++i) {
            int maxpre = _max;
            int minpre = _min;
            
            _max = max(max(maxpre * nums[i], minpre * nums[i]), nums[i]);
            _min = min(min(maxpre * nums[i], minpre * nums[i]), nums[i]);
            
            ans = max(ans, max(_max, _min));
        }
        return ans;
    }
};


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        int ans = nums[0];
        int minProd = ans, maxProd = ans;
        for (int i = 1; i < n; ++i) {
            int _minProd = minProd * nums[i];
            int _maxProd = maxProd * nums[i];
            minProd = min(min(_minProd, _maxProd), nums[i]);
            maxProd = max(max(_minProd, _maxProd), nums[i]);
            ans = max(ans, max(minProd, maxProd));
        }
        return ans;
    }
};