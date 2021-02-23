// 75. Sort Colors

// Runtime: 4 ms, faster than 69.48% of C++ online submissions for Sort Colors.
// Memory Usage: 8.7 MB, less than 75.44% of C++ online submissions for Sort Colors.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        int zero = 0;
        while (zero < n && nums[zero] == 0) ++zero;
        for (int i = zero; i < n; ++i) {
            if (zero < i && nums[i] == 0) {
                swap(nums[zero++], nums[i]);
            }
        }
        
        int two = n - 1;
        while (two >= 0 && nums[two] == 2) --two;
        for (int i = two; i >= zero; --i) {
            if (two > i && nums[i] == 2) {
                swap(nums[two--], nums[i]);
            }
        }
    }
};


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] == 0) {
                ++i;
                continue;
            }
            if (nums[j] == 2) {
                --j;
                continue;
            }
            bool swaped = false;
            for (int k = i; k <= j && !swaped; ++k) {
                if (nums[k] == 0) {
                    swap(nums[i], nums[k]);
                    swaped = true;
                } else if (nums[k] == 2) {
                    swap(nums[j], nums[k]);
                    swaped = true;
                }
            }
            if (!swaped) break;
        }
    }
};