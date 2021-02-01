// 41. First Missing Positive

// Runtime: 8 ms, faster than 6.50% of C++ online submissions for First Missing Positive.
// Memory Usage: 8.8 MB, less than 50.00% of C++ online submissions for First Missing Positive.

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int min_positive = 0;
        int max_num = INT_MIN;
        int cnt_positive = 0;
        for (int i : nums) {
            if (i > 0) {
                min_positive = min_positive == 0 ? i : min(min_positive, i);
                ++cnt_positive;
            }
            max_num = max(max_num, i);
        }
        
        // nums[i] <= 0 or min_positive > 1
        if (max_num <= 0 || min_positive > 1) return 1;
        
        // WRONG: [1, 3, 3]
        // [1, max_num]: Example [1, 2, 3, 4, 5]
        // if (max_num == cnt_positive) return max_num + 1;
        
        // [1, cnt_positive]: Example [1, 2, 3, 4, 5]
        // [1, max_num]:      Example [1, 2, 5, 7, 9]
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= 0 || nums[i] > cnt_positive || nums[i] == i + 1) continue;
            int j = i;
            while (j >= 0 && j < nums.size() && nums[j] != j + 1 && nums[j] >= 1 && nums[j] <= cnt_positive && nums[j] != nums[nums[j] - 1]) {
                swap(nums[j], nums[nums[j] - 1]);   
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return max_num + 1;
    }
};