// 888. Fair Candy Swap
// https://leetcode.com/problems/fair-candy-swap/

// Runtime: 180 ms, faster than 76.56% of C++ online submissions for Fair Candy Swap.
// Memory Usage: 48.4 MB, less than 57.87% of C++ online submissions for Fair Candy Swap.

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int diff = (accumulate(begin(A), end(A), 0) - accumulate(begin(B), end(B), 0)) / 2;
        unordered_set<int> s(begin(A), end(A));
        for (int b : B) if (s.count(b + diff)) return {b + diff, b};
        return {};
    }
};