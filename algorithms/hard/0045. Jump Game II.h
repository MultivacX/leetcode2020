// 45. Jump Game II

// Runtime: 8 ms, faster than 97.04% of C++ online submissions for Jump Game II.
// Memory Usage: 10.1 MB, less than 90.00% of C++ online submissions for Jump Game II.

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        int ans = 0;
        int l = 0;
        int r = 0;
        while (l < n - 1) {
            ++ans;
            
            int fatherest = 0;
            for (int i = l; i <= r; ++i) {
                fatherest = max(fatherest, nums[i] + i);
            }
            
            if (fatherest >= n - 1) {
                return ans;
            }

            l = r + 1;
            r = fatherest;
        }
        return ans;
    }
};