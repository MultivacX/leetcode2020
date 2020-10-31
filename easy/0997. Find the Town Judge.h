// 997. Find the Town Judge
// https://leetcode.com/problems/find-the-town-judge/

// Runtime: 396 ms, faster than 35.06% of C++ online submissions for Find the Town Judge.
// Memory Usage: 74.2 MB, less than 5.18% of C++ online submissions for Find the Town Judge.

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        // how many people trust i
        vector<int> beTrusted(1 + N, 0);
        for (auto t : trust) ++beTrusted[t[1]];
        int judge = -1;
        for (int i = 1; i <= N; ++i) {
            // Everybody (except for the town judge) trusts the town judge.
            if (beTrusted[i] == N - 1) {
                if (judge == - 1) judge = i;
                // There is exactly one person that satisfies properties 1 and 2.
                else return -1;
            }
        }
        // The town judge trusts nobody.
        for (auto t : trust) if (t[0] == judge) return -1;
        return judge;
    }
};