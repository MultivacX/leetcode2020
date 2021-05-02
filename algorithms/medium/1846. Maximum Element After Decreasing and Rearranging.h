// 1846. Maximum Element After Decreasing and Rearranging
// https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/

// Runtime: 92 ms, faster than 83.33% of C++ online submissions for Maximum Element After Decreasing and Rearranging.
// Memory Usage: 51.2 MB, less than 83.33% of C++ online submissions for Maximum Element After Decreasing and Rearranging.
    
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // Rearrange
        sort(begin(arr), end(arr));
        
        // Decrease
        const int n = arr.size();
        arr[0] = 1;
        for (int i = 1; i < n; ++i) 
            if (arr[i - 1] < arr[i])
                arr[i] = arr[i - 1] + 1;
        
        return arr[n - 1];
    }
};