// 806. Number of Lines To Write String
// https://leetcode.com/problems/number-of-lines-to-write-string/

// Runtime: 4 ms, faster than 36.67% of C++ online submissions for Number of Lines To Write String.
// Memory Usage: 7.3 MB, less than 68.10% of C++ online submissions for Number of Lines To Write String.
    
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> ans{1, 0};
        int w = 0;
        const int N = s.length();
        for (int i = 0; i < N; ++i) {
            int v = widths[s[i] - 'a'];
            if (w + v == 100) {
                if (i + 1 == N) ans[1] = 100;
                else w = 0, ++ans[0], ans[1] = 0;
            } else if (w + v > 100) {
                w = v, ++ans[0], ans[1] = w;
            } else {
                w += v;
                ans[1] = w;
            }
        }
        return ans;
    }
};