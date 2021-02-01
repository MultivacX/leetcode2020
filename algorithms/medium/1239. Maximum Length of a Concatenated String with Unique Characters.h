// 1239. Maximum Length of a Concatenated String with Unique Characters

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum Length of a Concatenated String with Unique Characters.
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Maximum Length of a Concatenated String with Unique Characters.

class Solution {
public:
    int maxLength(vector<string>& arr) {
        const int N = arr.size();
        vector<pair<int, int>> nums;
        for (const auto& s : arr) {
            int num = 0;
            for (const char& c : s) {
                int v = 1 << (c - 'a');
                if (num & v) {
                    num = 0;
                    break;
                }
                num |= v;
            }
            if (num) nums.push_back({num, s.length()});
        }
        int ans = 0;
        concate(nums, 0, 0, 0, ans);
        return ans;
    }
    
    void concate(const vector<pair<int, int>>& nums, int idx, int num, int len, int& ans) {
        ans = max(ans, len);
        for (int i = idx; i < nums.size(); ++i) {
            if (num & nums[i].first) continue;
            concate(nums, i + 1, num | nums[i].first, len + nums[i].second, ans);
        }
    }
};