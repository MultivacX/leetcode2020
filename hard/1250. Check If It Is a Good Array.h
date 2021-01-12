// 1250. Check If It Is a Good Array
// https://leetcode.com/problems/check-if-it-is-a-good-array/

// Runtime: 56 ms, faster than 100.00% of C++ online submissions for Check If It Is a Good Array.
// Memory Usage: 29.2 MB, less than 100.00% of C++ online submissions for Check If It Is a Good Array.
    
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        const int N = nums.size();
        int x = nums[0];
        for (int i = 1; i < N && x != 1; ++i) 
            x = gcd(x, nums[i]);
        return x == 1;
    }
};