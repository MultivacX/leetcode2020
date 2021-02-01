// 307. Range Sum Query - Mutable

// Runtime: 56 ms, faster than 56.14% of C++ online submissions for Range Sum Query - Mutable.
// Memory Usage: 19.4 MB, less than 25.00% of C++ online submissions for Range Sum Query - Mutable.

// Time Complexity: construct, O(n); update, O(lgn); sumRange, O(lgn).
// Space Complexity: O(n).

class NumArray {
    class segment_tree {
        const int n;
        vector<int> tree;

    public:
        segment_tree(vector<int>& nums) : n(nums.size()), tree(nums.size() << 1, 0) {
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
    
    segment_tree t;
    
public:
    NumArray(vector<int>& nums) : t(nums) {
    }
    
    void update(int i, int val) {
        t.update(i, val);
    }
    
    int sumRange(int i, int j) {
        return t.query(i, j + 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */