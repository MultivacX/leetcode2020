// 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// Runtime: 20 ms, faster than 59.10% of C++ online submissions for Remove Duplicates from Sorted Array.
// Memory Usage: 14.1 MB, less than 99.99% of C++ online submissions for Remove Duplicates from Sorted Array.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 1) return N;
        
        int i = 1;
        int j = -1;
        while (i < N && j < N) {
            if (nums[i - 1] < nums[i]) { 
                ++i;
                continue;
            }
            if (i >= j) j = i + 1;
            while (j < N) {
                if (nums[i] >= nums[j]) ++j;
                else {
                    swap(nums[i], nums[j]);
                    break;
                }
            } 
        }
        
        i = 1;
        int len = 1;
        while (i < N && nums[i - 1] < nums[i]) 
            ++i, ++len;
        return len;
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int n = nums.size();
        if (n < 2) return n;
        
        int i = 0, j = 0;
        while (j < n) {
            if (i != j && nums[i] != nums[j]) 
                swap(nums[++i], nums[j]);
            ++j;
        }
        return ++i;
    }
};