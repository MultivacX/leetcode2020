// 275. H-Index II
// https://leetcode.com/problems/h-index-ii/

// Runtime: 56 ms, faster than 7.29% of C++ online submissions for H-Index II.
// Memory Usage: 18.8 MB, less than 36.31% of C++ online submissions for H-Index II.

// Time Complexity: O(lg(N)).
// Space Complexity: O(N).

class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int N = citations.size();
        int l = 0;
        int r = N;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (N - m == citations[m]) return citations[m];
            else if (N - m > citations[m]) l = m + 1;
            else r = m;
        }
        return N - l;
    }
};