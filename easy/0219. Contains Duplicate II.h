// 219. Contains Duplicate II

// Runtime: 60 ms, faster than 5.95% of C++ online submissions for Contains Duplicate II.
// Memory Usage: 15.5 MB, less than 64.71% of C++ online submissions for Contains Duplicate II.

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k <= 0 || nums.empty()) return false;
        
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = m.find(nums[i]);
            if (it != m.end()) {
                if (i - it->second <= k) 
                    return true;
                else
                    m[nums[i]] = i;
            } else {
                m.insert({nums[i], i});
            }
        }
        return false;
    }
};