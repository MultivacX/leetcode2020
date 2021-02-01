// 376. Wiggle Subsequence

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Wiggle Subsequence.
// Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Wiggle Subsequence.

class Solution {
public:
    struct Record {
        Record(int v, int l, bool p) : val(v), len(l), positive(p) {}
        
        int val;
        int len;
        bool positive;
    };
    
    int wiggleMaxLength(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 1) return N;
        
        Record a(nums[0], 1, true);
        Record b(nums[0], 1, false);
        auto try_append_num = [](Record& record, int num){
            if (record.val == num) return;
            
            if ((record.val > num && record.positive) || (record.val < num && !record.positive)) {
                record.positive = !record.positive;
                ++record.len;
            }
            record.val = num;
        };
        for (int i = 1; i < N; ++i) {
            try_append_num(a, nums[i]);
            try_append_num(b, nums[i]);
        }
        return max(a.len, b.len);
    }
};