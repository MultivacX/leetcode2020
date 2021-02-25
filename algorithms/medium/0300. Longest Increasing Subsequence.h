// 300. Longest Increasing Subsequence

// Runtime: 32 ms, faster than 68.02% of C++ online submissions for Longest Increasing Subsequence.
// Memory Usage: 9.1 MB, less than 9.38% of C++ online submissions for Longest Increasing Subsequence.

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        map<int, int> m;
        int ans = 0;
        for (int i : nums) {
            auto ub = m.upper_bound(i);
            int cnt = 1;
            if (ub != m.end()) ub = m.end();
            for (auto it = m.begin(); it != ub && it->first < i; ++it) {
                cnt = max(cnt, it->second + 1);
            }
            m[i] = cnt;
            ans = max(ans, cnt);
        }
        return ans;
    }
};


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tmp{INT_MIN};
        for (int i = 0; i < nums.size(); ++i) {
            if (tmp.back() < nums[i]) {
                tmp.push_back(nums[i]);
            } else {
                auto it = lower_bound(begin(tmp), end(tmp), nums[i]);
                if (*it != nums[i]) *it = nums[i];
            }
        }
        return tmp.size() - 1;
    }
};