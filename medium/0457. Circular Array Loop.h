// 457. Circular Array Loop

// Runtime: 4 ms, faster than 71.50% of C++ online submissions for Circular Array Loop.
// Memory Usage: 7.9 MB, less than 100.00% of C++ online submissions for Circular Array Loop.

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return false;
        const int m = (5000 / n + 1) * n;
        auto next_idx = [&](int idx) {
            return (m + idx + nums[idx]) % n;
        };
        auto num = [&](int idx) {
            return nums[idx] <= 1000 ? nums[idx] : nums[idx] - m;
        };
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) continue;
            
            // printf("start [%d]=%d:\n", i, nums[i]);
            bool forward = nums[i] > 0;
            int curr = i;
            int length = 0;
            while (nums[curr] <= 1000) {
                // visited
                if (nums[curr] == 0) {
                    // printf("  WRONG: visited\n");
                    length = 0;
                    break;
                }
                
                int next = next_idx(curr);
                // printf("  [%d]:%d -> [%d]:%d\n", curr, nums[curr], next, num(next));
                
                // same idx
                if (curr == next) {
                    // printf("  WRONG: same idx\n");
                    length = 0;
                    break;
                }
                
                bool next_forward = num(next) > 0;
                // wrong direction
                if (forward != next_forward) {
                    // printf("  WRONG: wrong direction\n");
                    length = 0;
                    break;
                }
                
                if (nums[curr] <= 1000)
                    nums[curr] += m;
                curr = next;
                ++length;
            }
            if (length > 1)
                return true;
            
            curr = i;
            while (nums[curr] != 0) {
                int next = next_idx(curr);
                nums[curr] = 0;
                // printf("  [%d]:%d -> [%d]:%d\n", curr, nums[curr], next, num(next));
                
                // same idx
                if (curr == next) break;
                
                bool next_forward = num(next) > 0;
                // wrong direction
                if (forward != next_forward) break;
                
                curr = next;
            }
        }
        return false;
    }
};