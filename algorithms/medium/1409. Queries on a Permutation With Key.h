// 1409. Queries on a Permutation With Key
// https://leetcode.com/problems/queries-on-a-permutation-with-key/

// Runtime: 12 ms, faster than 90.13% of C++ online submissions for Queries on a Permutation With Key.
// Memory Usage: 8.6 MB, less than 74.89% of C++ online submissions for Queries on a Permutation With Key.
    
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        // P = [1, m]
        
        vector<int> positions(m);
        for (int i = 0; i < m; ++i) positions[i] = i; 
        
        const int N = queries.size();
        vector<int> ans(N);
        for (int i = 0, j = -1; i < N; ++i) {
            int val = queries[i];
            int pos = positions[val - 1];
            
            int p = 0;
            for (int i = 0; i < m; ++i)
                if (pos > positions[i]) ++p;
            ans[i] = p;
            
            positions[val - 1] = j--;
        }
        return ans;
    }
};