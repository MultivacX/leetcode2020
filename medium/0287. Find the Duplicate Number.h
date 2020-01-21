// 287. Find the Duplicate Number

// Runtime: 16 ms, faster than 31.96% of C++ online submissions for Find the Duplicate Number.
// Memory Usage: 10 MB, less than 37.50% of C++ online submissions for Find the Duplicate Number.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = -1;
        for (int i = 0; i < nums.size(); ++i) {
            int index = (nums[i] < 0 ? -nums[i] : nums[i]) - 1;
            bool visited = nums[index] < 0;
            if (visited) {
                ans = index + 1;
                break;
            }
            nums[index] *= -1;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) nums[i] *= -1;
        }
        return ans;
    }
};