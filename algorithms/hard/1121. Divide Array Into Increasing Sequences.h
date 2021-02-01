// 1121. Divide Array Into Increasing Sequences
// https://leetcode.com/problems/divide-array-into-increasing-sequences/

// Runtime: 180 ms, faster than 89.47% of C++ online submissions for Divide Array Into Increasing Sequences.
// Memory Usage: 73.1 MB, less than 100.00% of C++ online submissions for Divide Array Into Increasing Sequences.
    
class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        if (nums.size() == 1) return K == 1;
        
        int freq = 1;
        int diff = nums.size();
        for (int i = 0, f = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i - 1] == nums[i]) ++f;
            
            if ((i > 0 && nums[i - 1] != nums[i]) || i + 1 == nums.size()) {
                if (freq < f) {
                    freq = f;
                    diff = 1;
                } else if (freq == f) {
                    ++diff;
                }
            }
            
            if (i > 0 && nums[i - 1] != nums[i]) f = 1;
        }
        
        int seq_cnt = freq;
        int seq_len = diff + (nums.size() - freq * diff) / seq_cnt;
        
        return seq_len >= K;
    }
};