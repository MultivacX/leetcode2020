// 455. Assign Cookies
// https://leetcode.com/problems/assign-cookies/

// Runtime: 64 ms, faster than 95.39% of C++ online submissions for Assign Cookies.
// Memory Usage: 17.9 MB, less than 93.20% of C++ online submissions for Assign Cookies.

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        sort(begin(g), end(g));
        sort(begin(s), end(s));
        const int N = s.size();
        int i = 0;
        for (int c : g) {
            while (i < N && s[i] < c) ++i;
            if (i >= N) break;
            if (s[i] >= c) ++ans, ++i;
        }
        return ans;
    }
};