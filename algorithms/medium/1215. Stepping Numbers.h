// 1215. Stepping Numbers
// https://leetcode.com/problems/stepping-numbers/

// Runtime: 76 ms, faster than 15.56% of C++ online submissions for Stepping Numbers.
// Memory Usage: 19.4 MB, less than 33.33% of C++ online submissions for Stepping Numbers.
    
class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> nums{0,1,2,3,4,5,6,7,8,9};
        vector<int> ans;
        while (!nums.empty()) {
            vector<int> tmp;
            for (int num : nums) {
                if (num > high) break;
                if (num >= low && num <= high)
                    ans.push_back(num);
                
                int b = num % 10;
                int64_t n = num * (int64_t)10;
                if (n >= INT_MAX || n == num) continue;
                if (b - 1 >= 0) tmp.push_back(n + b - 1);
                if (b + 1 <= 9) tmp.push_back(n + b + 1);
            }
            nums = tmp;
        }
        return ans;
    }
};