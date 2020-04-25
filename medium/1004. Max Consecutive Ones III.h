// 1004. Max Consecutive Ones III

// Runtime: 60 ms, faster than 65.40% of C++ online submissions for Max Consecutive Ones III.
// Memory Usage: 11.8 MB, less than 100.00% of C++ online submissions for Max Consecutive Ones III.

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        const int N = A.size();
        int ans = 0;
        int k = 0;
        int s = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i] == 0) ++k;
            while (k > K && s <= i) {
                if (A[s++] == 0) --k;
            }
            if (s <= i) ans = max(ans, i - s + 1);
        }
        return ans;
    }
};