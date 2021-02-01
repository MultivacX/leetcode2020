// 660. Remove 9
// https://leetcode.com/problems/remove-9/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove 9.
// Memory Usage: 6.3 MB, less than 38.10% of C++ online submissions for Remove 9.
    
class Solution {
public:
    int newInteger(int n) {
        // base 10 -> base 9
        vector<int> nums;
        while (n) {
            int d = n % 9;
            n = n / 9;
            nums.push_back(d);
        }
        int ans = 0;
        for (int i = nums.size() - 1; i >= 0; --i)
            ans = ans * 10 + nums[i];
        return ans;
    }
};