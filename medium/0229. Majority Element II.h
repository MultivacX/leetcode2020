// 229. Majority Element II

// Runtime: 8 ms, faster than 99.53% of C++ online submissions for Majority Element II.
// Memory Usage: 10.6 MB, less than 73.33% of C++ online submissions for Majority Element II.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int num1 = 0; // init value doesn't matter
        int cnt2 = 0;
        int num2 = 0; // init value doesn't matter
        for (int num : nums) {
            if (num1 == num) {
                ++cnt1;
            } else if (num2 == num) {
                ++cnt2;
            } else if (cnt1 == 0) {
                ++cnt1;
                num1 = num;
            } else if (cnt2 == 0) {
                ++cnt2;
                num2 = num;
            } else {
                --cnt1;
                --cnt2;
            }
            
            // printf("%d:{%d}, %d:{%d}\n", cnt1, num1, cnt2, num2);
        }
        
        cnt1 = 0;
        cnt2 = 0;
        for (int num : nums) {
            if (num1 == num) ++cnt1;
            else if (num2 == num) ++cnt2;
        }
        
        const int n = nums.size() / 3;
        vector<int> ans;
        if (cnt1 > n) ans.push_back(num1);
        if (cnt2 > n) ans.push_back(num2);
        return ans;
    }
};