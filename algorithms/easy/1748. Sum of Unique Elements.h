// 1748. Sum of Unique Elements
// https://leetcode.com/problems/sum-of-unique-elements/

// Runtime: 4 ms, faster than 83.33% of C++ online submissions for Sum of Unique Elements.
// Memory Usage: 7.9 MB, less than 100.00% of C++ online submissions for Sum of Unique Elements.
    
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> cnt(101);
        for (int num : nums) ++cnt[num];
        int sum = 0;
        for (int i = 1; i <= 100; ++i)
            if (cnt[i] == 1)
                sum += i;
        return sum;
    }
};