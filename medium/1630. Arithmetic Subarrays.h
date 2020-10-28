// 1630. Arithmetic Subarrays
// https://leetcode.com/problems/arithmetic-subarrays/

// Runtime: 148 ms, faster than 81.54% of C++ online submissions for Arithmetic Subarrays.
// Memory Usage: 26 MB, less than 5.21% of C++ online submissions for Arithmetic Subarrays.

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size(), true);
        for (int i = 0; i < l.size(); ++i) {
            vector<int> sub(r[i] - l[i] + 1);
            for (int j = l[i], k = 0; j <= r[i]; ++j, ++k)
                sub[k] = nums[j];
            sort(begin(sub), end(sub));
            for (int k = 1, d = 0; k < sub.size(); ++k) {
                if (k == 1) d = sub[k] - sub[k - 1];
                else if (d != sub[k] - sub[k - 1]) {
                    ans[i] = false;
                    break;
                }
            }
        }
        return ans;
    }
};