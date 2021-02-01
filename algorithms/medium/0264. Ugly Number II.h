// 264. Ugly Number II

// Runtime: 16 ms, faster than 40.47% of C++ online submissions for Ugly Number II.
// Memory Usage: 11.8 MB, less than 68.42% of C++ online submissions for Ugly Number II.

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums{1};
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        while (nums.size() < n) {
            int n2 = nums[i2] * 2;
            while (n2 <= nums.back()) 
                n2 = nums[++i2] * 2;
            
            int n3 = nums[i3] * 3;
            while (n3 <= nums.back()) 
                n3 = nums[++i3] * 3;
            
            int n5 = nums[i5] * 5;
            while (n5 <= nums.back()) 
                n5 = nums[++i5] * 5;
            
            int min_num = min(n2, min(n3, n5));
            
            if (n2 == min_num) 
                ++i2;
            else if (n3 == min_num) 
                ++i3;
            else if (n5 == min_num) 
                ++i5;
            
            nums.push_back(min_num);
            // cout << min_num << ", ";
        }
        return nums.back();
    }
};