// 1558. Minimum Numbers of Function Calls to Make Target Array
// https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/

// Runtime: 96 ms, faster than 77.10% of C++ online submissions for Minimum Numbers of Function Calls to Make Target Array.
// Memory Usage: 25.8 MB, less than 15.78% of C++ online submissions for Minimum Numbers of Function Calls to Make Target Array.

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int add = 0;
        int mul = 0;
        for (int num : nums) {
            int m = 0;
            while (num > 0) {
                if (num & 1) num -= 1, ++add;
                if (num > 0) num >>= 1, ++m;
            }
            if (m > mul) mul = m;
        }
        return add + mul;
    }
};

// Runtime: 260 ms, faster than 5.85% of C++ online submissions for Minimum Numbers of Function Calls to Make Target Array.
// Memory Usage: 25.9 MB, less than 7.12% of C++ online submissions for Minimum Numbers of Function Calls to Make Target Array.
    
/*class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(rbegin(nums), rend(nums));
        int ans = 0;
        while (!nums.empty()) {
            for (int& i : nums) if (i & 1) --i, ++ans;
            while (!nums.empty() && nums.back() == 0) nums.pop_back();
            for (int& i : nums) i >>= 1;
            if (!nums.empty()) ++ans;
        }
        return ans;
    }
};*/