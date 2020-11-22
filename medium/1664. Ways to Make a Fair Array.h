// 1664. Ways to Make a Fair Array
// https://leetcode.com/problems/ways-to-make-a-fair-array/

// Runtime: 260 ms, faster than 60.00% of C++ online submissions for Ways to Make a Fair Array.
// Memory Usage: 103.4 MB, less than 40.00% of C++ online submissions for Ways to Make a Fair Array.
    
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        const int N = nums.size();
        vector<int> prefix_e(N, 0), prefix_o(N, 0);
        for (int i = 0; i < N; ++i) {
            prefix_e[i] += (i & 1 ? 0 : 1) * nums[i] + (i > 0 ? prefix_e[i - 1] : 0);
            prefix_o[i] += (i & 1 ? 1 : 0) * nums[i] + (i > 0 ? prefix_o[i - 1] : 0);
            // cout << prefix_e[i] << '|' << prefix_o[i] << ' ';
        }
        // cout << endl;
            
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            int sum_a = (i > 0 ? prefix_o[i - 1] : 0) + prefix_e[N - 1] - prefix_e[i];
            int sum_b = (i > 0 ? prefix_e[i - 1] : 0) + prefix_o[N - 1] - prefix_o[i];
            if (sum_a == sum_b) ++ans;
        }
        return ans;
    }
};