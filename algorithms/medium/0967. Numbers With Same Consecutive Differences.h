// 967. Numbers With Same Consecutive Differences

// Runtime: 8 ms, faster than 50.96% of C++ online submissions for Numbers With Same Consecutive Differences.
// Memory Usage: 7.6 MB, less than 100.00% of C++ online submissions for Numbers With Same Consecutive Differences.

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> ans;
        for (int i = 0; i <= 9; ++i) {
            if (N == 1) {
                ans.push_back(i);
            } else if (i != 0) {
                f(N - 1, K, i, i, ans);
            }
        }
        return ans;
    }
    
    void f(int N, int K, int i, int num, vector<int>& ans) {
        if (N == 0) {
            ans.push_back(num);
            return;
        }
        
        if (K == 0) {
            f(N - 1, K, i, num * 10 + i, ans);
        } else {
            if (i + K <= 9) f(N - 1, K, i + K, num * 10 + i + K, ans);
            if (i - K >= 0) f(N - 1, K, i - K, num * 10 + i - K, ans);   
        }
    }
};