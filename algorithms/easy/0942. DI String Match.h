// 942. DI String Match
// https://leetcode.com/problems/di-string-match/

// Runtime: 4 ms, faster than 95.08% of C++ online submissions for DI String Match.
// Memory Usage: 8.8 MB, less than 96.07% of C++ online submissions for DI String Match.
    
class Solution {
public:
    vector<int> diStringMatch(string S) {
        const int N = S.length();
        vector<int> ans(N + 1);
        int l = 0, r = N;
        for (int i = 0; i < N; ++i) {
            if (S[i] == 'I') ans[i] = l++;
            else ans[i] = r--;
        }
        ans[N] = l;
        return ans;
    }
};