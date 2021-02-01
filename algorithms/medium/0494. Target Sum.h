// 494. Target Sum

// Runtime: 1200 ms, faster than 5.42% of C++ online submissions for Target Sum.
// Memory Usage: 7.7 MB, less than 100.00% of C++ online submissions for Target Sum.

class Solution {
public:
    // TODO: optim
    // The length of the given array is positive and will not exceed 20.
    // static const int IDX = 30;
    // int getKey(int num, int idx) { return num * IDX + idx; }
    // int getNum(int key) { return key / IDX; }
    // int getIdx(int key) { return key % IDX; }
    
    
    
    int findTargetSumWays(vector<int>& nums, int S) {
        int cnt = 0;
        count(nums, 0, S, cnt);
        return cnt;
    }
    
    void count(vector<int>& nums, int idx, int64_t S, int& cnt) {
        if (idx >= nums.size()) {
            cnt += S == 0 ? 1 : 0;
            return;
        }
        count(nums, idx + 1, S + nums[idx], cnt);
        count(nums, idx + 1, S - nums[idx], cnt);
    }
};