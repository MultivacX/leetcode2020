// 229. Majority Element II

// WRONG
/*class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int num1 = 0;
        int cnt2 = 0;
        int num2 = 0;
        for (int num : nums) {
            if (cnt1 == 0) {
                ++cnt1;
                num1 = num;
            } else if (num1 == num) {
                ++cnt1;
            } else if (cnt2 == 0) {
                ++cnt2;
                num2 = num;
            } else if (num2 == num) {
                ++cnt2;
            } else if (cnt1 < cnt2) {
                --cnt1;
            } else {
                --cnt2;
            }
            
            printf("%d:{%d}, %d:{%d}\n", cnt1, num1, cnt2, num2);
        }
        
        const int n = nums.size() / 3;
        int c1 = 0;
        int c2 = 0;
        vector<int> ans;
        for (int num : nums) {
            if (num1 == num && ++c1 > n) {
                if (ans.empty() || ans.back() != num) 
                    ans.push_back(num);
                c1 = INT_MIN;
            } else if (num2 == num && ++c2 > n) {
                if (ans.empty() || ans.back() != num) 
                    ans.push_back(num);
                c2 = INT_MIN;
            }
        }
        return ans;
    }
};*/