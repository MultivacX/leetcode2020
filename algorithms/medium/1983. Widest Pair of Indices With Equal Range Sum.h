// 1983. Widest Pair of Indices With Equal Range Sum
// https://leetcode.com/problems/widest-pair-of-indices-with-equal-range-sum/

// Runtime: 529 ms, faster than 14.77% of C++ online submissions for Widest Pair of Indices With Equal Range Sum.
// Memory Usage: 199.6 MB, less than 70.45% of C++ online submissions for Widest Pair of Indices With Equal Range Sum.
    
class Solution {
public:
    int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size();
        int w = 0;
        unordered_map<int, int> diff_idx{{0, -1}};
        for (int i = 0, diff = 0; i < n; ++i) {
            diff += nums1[i] - nums2[i];
            auto it = diff_idx.find(diff);
            if (it == diff_idx.end()) {
                diff_idx.emplace(diff, i);
            } else {
                w = max(w, i - it->second);
            }
        }
        return w;
    }
};