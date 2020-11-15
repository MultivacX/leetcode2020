// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/

// Runtime: 8 ms, faster than 93.66% of C++ online submissions for Intersection of Two Arrays.
// Memory Usage: 10.9 MB, less than 34.56% of C++ online submissions for Intersection of Two Arrays.

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        unordered_set<int> s(begin(nums1), end(nums1));
        vector<int> ans;
        for (int i : nums2) {
            if (s.count(i)) {
                ans.push_back(i);
                s.erase(i);
            }
        }
        return ans;
    }
};