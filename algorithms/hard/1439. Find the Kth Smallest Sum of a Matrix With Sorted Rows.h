// 1439. Find the Kth Smallest Sum of a Matrix With Sorted Rows
// https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/

// Runtime: 92 ms, faster than 84.32% of C++ online submissions for Find the Kth Smallest Sum of a Matrix With Sorted Rows.
// Memory Usage: 33.3 MB, less than 57.84% of C++ online submissions for Find the Kth Smallest Sum of a Matrix With Sorted Rows.
    
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        auto& row = mat[0];
        for (int i = 1; i < mat.size(); ++i) {
            vector<int> cur;
            for (int j = 0; j < mat[i].size(); ++j) 
                for (int v : row) 
                    cur.push_back(v + mat[i][j]);
            
            sort(begin(cur), end(cur));
            if (cur.size() > k) 
                cur.resize(k);
            swap(cur, row);
        }
        return row.back();
    }
};