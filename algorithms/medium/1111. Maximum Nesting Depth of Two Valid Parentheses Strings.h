// 1111. Maximum Nesting Depth of Two Valid Parentheses Strings
// https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/

// Runtime: 1264 ms, faster than 10.03% of C++ online submissions for Maximum Nesting Depth of Two Valid Parentheses Strings.
// Memory Usage: 714.8 MB, less than 7.52% of C++ online submissions for Maximum Nesting Depth of Two Valid Parentheses Strings.

class Solution {
    int N;
    int D;
    vector<int> ans;
    
    void dfs(const string& seq, int idx, int A, int B, int d, vector<int>& v, vector<vector<int>>& memo) {
        if (idx >= N) {
            if (d < D) D = d, ans = v;
            return;
        }
        if (d >= D) return;
        if (memo[idx][d] != N) return;
        memo[idx][d] = d;
        
        if (seq[idx] == '(') {
            v[idx] = 0;
            dfs(seq, idx + 1, A + 1, B, max(d, max(A + 1, B)), v, memo);
            
            v[idx] = 1;
            dfs(seq, idx + 1, A, B + 1, max(d, max(A, B + 1)), v, memo);
        } else {
            if (A > 0) {
                v[idx] = 0;
                dfs(seq, idx + 1, A - 1, B, d, v, memo);
            }
            
            if (B > 0) {
                v[idx] = 1;
                dfs(seq, idx + 1, A, B - 1, d, v, memo);
            }
        }
    }
    
public:
    vector<int> maxDepthAfterSplit(string seq) {
        N = seq.length();
        D = N;
        vector<int> v(N, 0);
        vector<vector<int>> memo(N, vector<int>(N, N));
        dfs(seq, 1, 1, 0, 1, v, memo);
        return ans;
    }
};