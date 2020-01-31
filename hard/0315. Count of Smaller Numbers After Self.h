// 315. Count of Smaller Numbers After Self

class Solution {
public:
	// Time Limit Exceeded
	// 16 / 16 test cases passed, but took too long.
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;
        multiset<int> s;
        for (int i = nums.size() - 1; i >= 0; --i) {
            auto it = s.lower_bound(nums[i]);
            if (it == s.end()) {
                ans.push_back(s.size());
            } else {
                ans.push_back(distance(s.begin(), it));
            }
            s.insert(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};