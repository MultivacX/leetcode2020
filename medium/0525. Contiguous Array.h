// 525. Contiguous Array

// Runtime: 132 ms, faster than 39.51% of C++ online submissions for Contiguous Array.
// Memory Usage: 19.3 MB, less than 100.00% of C++ online submissions for Contiguous Array.

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m; // {cnt_offset, first_idx}
        m.insert({0, -1});
        int cnt0 = 0;
        int cnt1 = 0;
        int len = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) ++cnt0;
            else ++cnt1;
            
            int offset = cnt0 - cnt1;
            if (!m.count(offset)) {
                m.insert({offset, i});
                continue;
            }
            
            len = max(len, i - m[offset]);
        }
        return len;
    }
};