// 350. Intersection of Two Arrays II
// https://leetcode.com/problems/intersection-of-two-arrays-ii/

// Runtime: 12 ms, faster than 57.26% of C++ online submissions for Intersection of Two Arrays II.
// Memory Usage: 10.7 MB, less than 76.48% of C++ online submissions for Intersection of Two Arrays II.

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        // {num1, cnt1}
        unordered_map<int, int> m;
        for (int i : nums1) ++m[i];
        vector<int> ans;
        for (int i : nums2) {
            if (!m.count(i) || m[i] <= 0) continue;
            --m[i];
            ans.push_back(i);
        }
        return ans;
    }
};