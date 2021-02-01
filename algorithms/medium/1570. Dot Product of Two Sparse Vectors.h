// 1570. Dot Product of Two Sparse Vectors
// https://leetcode.com/problems/dot-product-of-two-sparse-vectors/

// Runtime: 520 ms, faster than 16.21% of C++ online submissions for Dot Product of Two Sparse Vectors.
// Memory Usage: 204 MB, less than 6.14% of C++ online submissions for Dot Product of Two Sparse Vectors.
    
class SparseVector {
    vector<pair<int, int>> m;
    
public:
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i)
            m.push_back({i, nums[i]});
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ans = 0;
        int i = 0, j = 0;
        while (i < m.size() && j < vec.m.size()) {
            if (m[i].first == vec.m[j].first) 
                ans += m[i++].second * vec.m[j++].second;
            else if (m[i].first < vec.m[j].first) ++i;
            else ++j;
        }
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);