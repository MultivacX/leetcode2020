// 961. N-Repeated Element in Size 2N Array
// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

// Runtime: 40 ms, faster than 96.01% of C++ online submissions for N-Repeated Element in Size 2N Array.
// Memory Usage: 24.6 MB, less than 98.05% of C++ online submissions for N-Repeated Element in Size 2N Array.
    
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> s;
        for (int a : A)
            if (!s.insert(a).second)
                return a;
        return 0;
    }
};