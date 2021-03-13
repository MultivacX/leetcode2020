// 169. Majority Element

// Runtime: 16 ms, faster than 96.98% of C++ online submissions for Majority Element.
// Memory Usage: 11 MB, less than 96.97% of C++ online submissions for Majority Element.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int cur = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (cnt == 0) {
                ++cnt;
                cur = nums[i];
            }
            else if (cur == nums[i]) ++cnt;
            else --cnt;
        }
        return cur;
    }
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0, cnt = 0;
        for (int i : nums) {
            if (cnt == 0) {
                ans = i;
                ++cnt;
            } else if (ans == i) {
                ++cnt;
            } else {
                --cnt;
            }
        }
        return ans;
    }
};