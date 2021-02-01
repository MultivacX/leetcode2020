// 1442. Count Triplets That Can Form Two Arrays of Equal XOR
// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/

// Runtime: 4 ms, faster than 90.94% of C++ online submissions for Count Triplets That Can Form Two Arrays of Equal XOR.
// Memory Usage: 8.2 MB, less than 6.12% of C++ online submissions for Count Triplets That Can Form Two Arrays of Equal XOR.

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // a ^ a = 0
        // a ^ 0 = a
        int ans = 0;
        unordered_map<int, vector<int>> m{{arr[0], vector<int>{0}}};
        for (int k = 1, preXOR = arr[0]; k < arr.size(); ++k) {
            preXOR ^= arr[k];
            if (preXOR == 0) {
                // 1. xor[0, k] == 0
                // 2. xor[0, j-1] == xor[j, k], 0 < j <= k
                ans += k;
            }
            for (auto i_ : m[preXOR]) {
                // i = 0, j = i_+1, 0 < j <= k
                // 1. xor[0, i_] == xor[0, i_] ^ xor[j, k]
                // 2. xor[j, k] == 0
                ans += k - (i_ + 1);
            }
            m[preXOR].push_back(k);
        }
        return ans;
    }
};