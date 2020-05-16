// 189. Rotate Array

// Runtime: 12 ms, faster than 78.46% of C++ online submissions for Rotate Array.
// Memory Usage: 10.1 MB, less than 8.33% of C++ online submissions for Rotate Array.

// Time Complexity: O(N).
// Space Complexity: O(1).

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int N = nums.size();
        k %= N;
        if (k == 0) return;
        
        int l = N - k; 
        int r = N - 1;
        while (l < r) swap(nums[l++], nums[r--]);
        // for (int i : nums) cout << i << " "; cout << endl;
        
        l = 0; 
        r = N - 1;
        while (l < r) swap(nums[l++], nums[r--]);
        // for (int i : nums) cout << i << " "; cout << endl;
        
        l = k; 
        r = N - 1;
        while (l < r) swap(nums[l++], nums[r--]);
        // for (int i : nums) cout << i << " "; cout << endl;
    }
};