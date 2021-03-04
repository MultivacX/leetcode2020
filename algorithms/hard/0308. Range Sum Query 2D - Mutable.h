// 308. Range Sum Query 2D - Mutable
// https://leetcode.com/problems/range-sum-query-2d-mutable/

// Runtime: 28 ms, faster than 66.82% of C++ online submissions for Range Sum Query 2D - Mutable.
// Memory Usage: 12.7 MB, less than 77.49% of C++ online submissions for Range Sum Query 2D - Mutable.

class NumMatrix {
    class segment_tree {
        const int n;
        vector<int> tree;

    public:
        segment_tree(const vector<int>& nums) : n(nums.size()), tree(nums.size() << 1, 0) {
            for (int i = 0; i < n; ++i)
                tree[n + i] = nums[i];
            for (int i = n - 1; i > 0; --i)
                tree[i] = tree[i << 1] + tree[i << 1 ^ 1];
        }

        void update(int i, int val) {
            for (int j = n + i, diff = val - tree[n + i]; j > 0; j >>= 1)
                tree[j] += diff;
        }

        int query(int l, int r) {
            int sum = 0;
            // [l, r)
            for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                if (l & 1) sum += tree[l++];
                if (r & 1) sum += tree[--r];
            }
            return sum;
        }
    };
    
    vector<segment_tree> trees;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for (const auto& nums : matrix) 
            trees.emplace_back(nums);
    }
    
    void update(int row, int col, int val) {
        trees[row].update(col, val);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int r = row1; r <= row2; ++r)
            sum += trees[r].query(col1, col2 + 1);
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */