// 303. Range Sum Query - Immutable

// Runtime: 32 ms, faster than 78.33% of C++ online submissions for Range Sum Query - Immutable.
// Memory Usage: 17.3 MB, less than 79.31% of C++ online submissions for Range Sum Query - Immutable.

class NumArray {
public:
    NumArray(vector<int>& nums) : sums(nums) {
        for (int i = 1; i < sums.size(); ++i) 
            sums[i] += sums[i - 1];
    }
    
    int sumRange(int i, int j) {
        return sums[j] - (i < 1 ? 0 : sums[i - 1]);
    }
    
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */