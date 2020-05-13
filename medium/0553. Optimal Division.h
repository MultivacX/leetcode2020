// 553. Optimal Division

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Optimal Division.
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Optimal Division.

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        const int N = nums.size();
        if (N == 1) return to_string(nums[0]);
        if (N == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);
        string ans(to_string(nums[0]) + "/(");
        for (int i = 1; i < N; ++i) {
            ans += to_string(nums[i]);
            if (i != N - 1) ans += "/";
        }
        ans += ")";
        return ans;
    }
};