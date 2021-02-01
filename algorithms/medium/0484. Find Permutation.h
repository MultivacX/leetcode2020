// 484. Find Permutation
// https://leetcode.com/problems/find-permutation/

// Runtime: 16 ms, faster than 25.23% of C++ online submissions for Find Permutation.
// Memory Usage: 10 MB, less than 74.77% of C++ online submissions for Find Permutation.
    
class Solution {
public:
    vector<int> findPermutation(string s) {
        const int N = s.length();
        vector<int> ans(N + 1);
        stack<int> t;
        int j = 0;
        for (int i = 0; i < N; ++i) {
            if (s[i] == 'D') {
                t.push(i + 1);
            } else {
                ans[j++] = i + 1;
                while (!t.empty()) {
                    ans[j++] = t.top();
                    t.pop();
                }
            }
        }
        t.push(N + 1);
        while (!t.empty()) {
            ans[j++] = t.top();
            t.pop();
        }
        return ans;
    }
};