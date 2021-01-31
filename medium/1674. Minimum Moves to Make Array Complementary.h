// 1674. Minimum Moves to Make Array Complementary
// https://leetcode.com/problems/minimum-moves-to-make-array-complementary/

// Runtime: 1812 ms, faster than 5.04% of C++ online submissions for Minimum Moves to Make Array Complementary.
// Memory Usage: 151.2 MB, less than 10.84% of C++ online submissions for Minimum Moves to Make Array Complementary.
    
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        const int n = nums.size();
        vector<vector<int>> min_nums(n / 2);
        vector<vector<int>> max_nums(n / 2);
        unordered_map<int, int> sums;
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            int x = min(nums[i], nums[j]);
            int y = max(nums[i], nums[j]);
            min_nums[i] = {x, y};
            max_nums[i] = {y, x};
            ++sums[x + y];
        }
        auto min_comp = [](const vector<int>& l, const vector<int>& r){
            return l[0] < r[0];
        };
        auto max_comp = [](const vector<int>& l, const vector<int>& r){
            return l[0] < r[0];
        };
        sort(begin(min_nums), end(min_nums), min_comp);
        sort(begin(max_nums), end(max_nums), max_comp);
        
        // i < j
        //     1. min_nums[i][0] <= min_nums[j][0]
        //        min_nums[i][0] <= min_nums[i][1]
        //     2. max_nums[i][0] <= max_nums[j][0]
        //        max_nums[i][0] >= max_nums[i][0]
        
        // moves:
        //      m1. x + y             == target -> 0
        //      m2. min(x, y) + 1      > target -> 2
        //      m3. max(x, y) + limit  < target -> 2
        //      m4.                             -> 1
        int ans = n;
        auto t2 = vector<int>{0, 0};
        auto t3 = vector<int>{0, 0};
        for (int target = 2; target <= limit * 2; ++target) {
            // m2. xi = min_nums[i][0] <= yi = min_nums[i][1]
            //     xi + 1 > target   
            t2[0] = t2[1] = target - 1;
            int cnt2 = end(min_nums) - upper_bound(begin(min_nums), end(min_nums), t2, min_comp);
            
            // m3. xi = max_nums[i][0] >= yi = max_nums[i][1]
            //     xi + limit < target   
            t3[0] = t3[1] = target - limit;
            int cnt3 = 0;
            if (t3[0] > 0) {
                cnt3 = lower_bound(begin(max_nums), end(max_nums), t3, max_comp) - begin(max_nums);
            }
            
            // m4
            int moves = n / 2 - cnt2 - cnt3;
            moves -= sums.count(target) ? sums[target] : 0;
            // m2 + m3
            moves += cnt2 * 2 + cnt3 * 2;
            ans = min(ans, moves);
        }
        return ans;
    }
};