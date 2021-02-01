// 453. Minimum Moves to Equal Array Elements

// Runtime: 52 ms, faster than 67.38% of C++ online submissions for Minimum Moves to Equal Array Elements.
// Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for Minimum Moves to Equal Array Elements.

class Solution {
public:
    int minMoves(vector<int>& nums) {
        const int64_t n = nums.size();
        if (n <= 1) return 0;
        
        int64_t min_num = nums[0];
        int64_t max_num = nums[0];
        for (int num : nums) {
            min_num = min(min_num, (int64_t)num);
            max_num = max(max_num, (int64_t)num);
        }
        int64_t moves = max_num - min_num;
        if (moves == 0) return 0;
        
        int64_t sum = 0;
        for (int num : nums) 
            sum += num;
        // n * max_num <= n * v = sum + (n - 1) * moves
        // moves >= max_num - min_num
        int64_t v = max_num;
        // Time Limit Exceeded
        /*while (n * v != sum + (n - 1) * moves) {
            ++v;
            ++moves;
        }*/
        // n * (v + t) = sum + (n - 1) * (moves + t)
        int64_t t = sum + (n - 1) * moves - n * v;
        return moves + t;
    }
};