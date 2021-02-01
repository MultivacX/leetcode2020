// 985. Sum of Even Numbers After Queries
// https://leetcode.com/problems/sum-of-even-numbers-after-queries/

// Runtime: 196 ms, faster than 52.09% of C++ online submissions for Sum of Even Numbers After Queries.
// Memory Usage: 45.8 MB, less than 89.20% of C++ online submissions for Sum of Even Numbers After Queries.
    
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum = 0;
        for (int a : A) if (a % 2 == 0) sum += a;
        vector<int> ans(queries.size(), 0);
        for (int i = 0; i < queries.size(); ++i) {
            const auto& q = queries[i];
            int cur = A[q[1]];
            A[q[1]] = cur + q[0];
            if (cur % 2 == 0) sum -= cur;
            if (A[q[1]] % 2 == 0) sum += A[q[1]];
            ans[i] = sum;
        }
        return ans;
    }
};