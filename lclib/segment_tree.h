#ifndef _lclib_segment_tree_h_
#define _lclib_segment_tree_h_

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

#endif // _lclib_segment_tree_h_