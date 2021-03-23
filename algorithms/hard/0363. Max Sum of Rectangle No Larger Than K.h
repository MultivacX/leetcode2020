// 363. Max Sum of Rectangle No Larger Than K
// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

// Runtime: 368 ms, faster than 70.69% of C++ online submissions for Max Sum of Rectangle No Larger Than K.
// Memory Usage: 99.6 MB, less than 62.98% of C++ online submissions for Max Sum of Rectangle No Larger Than K.
    
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        
        int ans = INT_MIN;
        for (int l = 0; l < n; ++l) {
            // rows[i] = matrix[i][l] + ... + matrix[i][r]
            vector<int> rows(m);
            for (int r = l; r < n; ++r) {
                for (int i = 0; i < m; ++i)
                    rows[i] += matrix[i][r];
                
                set<int> pres{0};
                int sum = 0;
                for (int row : rows) {
                    // sum - pre <= k
                    sum += row;
                    auto it = pres.lower_bound(sum - k);
                    if (it != pres.end()) {
                        int target = sum - *it;
                        if (target > ans) ans = target;
                    }
                    pres.insert(sum);
                    if (sum <= k && sum > ans) ans = sum;
                }
            }
        }
        return ans;
    }
};