// 1486. XOR Operation in an Array
// https://leetcode.com/problems/xor-operation-in-an-array/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for XOR Operation in an Array.
// Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for XOR Operation in an Array.
    
class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = start;
        for (int i = 1; i < n; ++i)
            ans ^= start + 2 * i;
        return ans;
    }
};