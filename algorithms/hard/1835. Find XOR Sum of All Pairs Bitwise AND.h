// 1835. Find XOR Sum of All Pairs Bitwise AND
// https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/

// Runtime: 116 ms, faster than 97.30% of C++ online submissions for Find XOR Sum of All Pairs Bitwise AND.
// Memory Usage: 93.5 MB, less than 84.47% of C++ online submissions for Find XOR Sum of All Pairs Bitwise AND.
    
class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xor2 = 0;
        for (int i : arr2) xor2 ^= i;
        
        int sum = 0;
        for (int i : arr1) sum ^= i & xor2;
        return sum;
    }
};