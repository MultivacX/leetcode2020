// 1512. Number of Good Pairs
// https://leetcode.com/problems/number-of-good-pairs/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Good Pairs.
// Memory Usage: 7.9 MB, less than 7.97% of C++ online submissions for Number of Good Pairs.
    
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i : nums) ++m[i];
        int ans = 0;
        for (auto it : m) ans += it.second * (it.second - 1) / 2;
        return ans;
    }
};