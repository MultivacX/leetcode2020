// 1885. Count Pairs in Two Arrays
// https://leetcode.com/problems/count-pairs-in-two-arrays/

// Runtime: 640 ms, faster than 100.00% of C++ online submissions for Count Pairs in Two Arrays.
// Memory Usage: 183.3 MB, less than 100.00% of C++ online submissions for Count Pairs in Two Arrays.
    
class Solution {
    long long ans = 0;
    
    void mergeSort(vector<int>& nums, int l, int r) {
        // [l, r)
        if (l + 1 >= r) return;
        
        int m = l + (r - l) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m, r);
        
        // i = [l, m)
        // nums[i] == nums1[i] - nums2[i]
        // find j: j = [m, r)
        //     nums1[i] - nums2[i] > nums2[j] - nums1[j] 
        //     nums[i] > -nums[j]
        //     -nums[i] < nums[j]
        auto middle = nums.begin() + m;
        auto right = nums.begin() + r;
        for (int i = l; i < m; ++i) {
            // *it > -nums[i]
            auto it = upper_bound(middle, right, -nums[i]);
            ans += right - it;
        }
        
        inplace_merge(nums.begin() + l, middle, right);
    }
    
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        // nums1[i] + nums1[j] > nums2[i] + nums2[j]
        for (int i = 0; i < nums1.size(); ++i)
            nums1[i] -= nums2[i];
        mergeSort(nums1, 0, nums1.size());
        return ans;
    }
};