// 268. Missing Number

// Runtime: 24 ms, faster than 80.51% of C++ online submissions for Missing Number.
// Memory Usage: 9.8 MB, less than 88.24% of C++ online submissions for Missing Number.

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n + 1) * n / 2;
        for (int i : nums) sum -= i;
        return sum;
    }
};