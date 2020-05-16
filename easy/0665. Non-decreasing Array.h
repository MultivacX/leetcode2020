// 665. Non-decreasing Array

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        const int N = nums.size();
        int minv = INT_MIN;
        int maxv = INT_MAX;
        for (int i = 0, cnt = 0; i < N; ++i) {
            int& a = i == 0 ? minv : nums[i - 1];
            int& b = nums[i];
            int& c = i == N - 1 ? maxv : nums[i + 1];
            if (a <= b && b <= c) continue;
            
            if (a > b) {
                if (b > c) return false;
                // nums[i-2] <= a > b <= c
                ++cnt;
            } else if (a > c) {
                
            } else if (b > c) {
                
            }
            
            if (cnt > 1) return false;
        }
        return true;
    }
};