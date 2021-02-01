// 274. H-Index
// https://leetcode.com/problems/h-index/

// Runtime: 8 ms, faster than 37.32% of C++ online submissions for H-Index.
// Memory Usage: 8.6 MB, less than 80.61% of C++ online submissions for H-Index.

class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int N = citations.size();
        if (N == 0) return 0;
        sort(begin(citations), end(citations));
        int ans = 0;
        for (int i = 0; i < N; ++i)
            ans = max(ans, min(N - i, citations[i]));
        return ans;
    }
};