// 1394. Find Lucky Integer in an Array
// https://leetcode.com/problems/find-lucky-integer-in-an-array/

// Runtime: 8 ms, faster than 92.04% of C++ online submissions for Find Lucky Integer in an Array.
// Memory Usage: 10.5 MB, less than 78.12% of C++ online submissions for Find Lucky Integer in an Array.

class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> cnt(501, 0);
        for (int a : arr) ++cnt[a];
        for (int i = 500; i > 0; --i)
            if (i == cnt[i])
                return i;
        return -1;
    }
};