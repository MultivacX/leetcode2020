// 821. Shortest Distance to a Character
// https://leetcode.com/problems/shortest-distance-to-a-character/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Shortest Distance to a Character.
// Memory Usage: 7.1 MB, less than 92.13% of C++ online submissions for Shortest Distance to a Character.
    
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        const int N = S.length();
        vector<int> c;
        for (int i = 0; i < N; ++i)
            if (S[i] == C)
                c.push_back(i);
        vector<int> ans(N, N);
        for (int i = 0, j = 0; i < N; ++i) {
            int a = abs(c[j] - i);
            int b = abs((j + 1 < c.size() ? c[j + 1] : N * 2) - i);
            ans[i] = min(a, b);
            if (a >= b) ++j;
        }
        return ans;
    }
};