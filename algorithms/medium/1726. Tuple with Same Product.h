// 1726. Tuple with Same Product
// https://leetcode.com/problems/tuple-with-same-product/

// Runtime: 608 ms, faster than 45.45% of C++ online submissions for Tuple with Same Product.
// Memory Usage: 81.7 MB, less than 100.00% of C++ online submissions for Tuple with Same Product.
    
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // a * b = c * d
        // a == c -> b == d
        unordered_map<int, int> m;
        for (int i = 0; i + 1 < nums.size(); ++i) 
            for (int j = i + 1; j < nums.size(); ++j) 
                ++m[nums[i] * nums[j]];
        int ans = 0;    
        for (const auto& it : m)
            ans += it.second * (it.second - 1) * 4;
        return ans;
    }
};