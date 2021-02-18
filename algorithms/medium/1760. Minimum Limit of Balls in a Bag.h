// 1760. Minimum Limit of Balls in a Bag
// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/

// Runtime: 172 ms, faster than 66.70% of C++ online submissions for Minimum Limit of Balls in a Bag.
// Memory Usage: 55.9 MB, less than 5.61% of C++ online submissions for Minimum Limit of Balls in a Bag.
    
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = 1000000001;
        while (l < r) {
            int m = l + (r - l) / 2;
            int opt = 0;
            for (const int& i : nums) 
                opt += (i - 1) / m;
            if (opt <= maxOperations) r = m;
            else l = m + 1;
        }
        return l;
    }
};