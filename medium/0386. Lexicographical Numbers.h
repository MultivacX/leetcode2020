// 386. Lexicographical Numbers

// Runtime: 12 ms, faster than 99.78% of C++ online submissions for Lexicographical Numbers.
// Memory Usage: 10.5 MB, less than 100.00% of C++ online submissions for Lexicographical Numbers.

// Time Complexity: O(n).
// Space Complexity: O(n).

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> nums(n, 0);
        int idx = 0;
        for (int i = 1; i <= 9; ++i) f(n, i, nums, idx);
        return nums;
    }
    
    void f(int n, int cur, vector<int>& nums, int& idx) {
        if (cur <= n) nums[idx++] = cur;
        else return;
        
        for (int i = 0; i <= 9; ++i) {
            int v = cur * 10 + i;
            f(n, v, nums, idx);
        }
    }
};