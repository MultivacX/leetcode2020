// 220. Contains Duplicate III

// Runtime: 20 ms, faster than 57.13% of C++ online submissions for Contains Duplicate III.
// Memory Usage: 10.9 MB, less than 77.27% of C++ online submissions for Contains Duplicate III.

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k <= 0 || t < 0 || nums.empty()) return false;
        
        multiset<int64_t> s;
        for (int i = 0; i < nums.size(); ++i) {
            int removedIdx = i - k - 1;
            if (removedIdx >= 0) 
                s.erase(s.find(nums[removedIdx]));
            // -t <= x - y <= t
            auto it = s.lower_bound((int64_t)nums[i] - (int64_t)t);
            if (it != s.end() && *it <= (int64_t)nums[i] + (int64_t)t)
                return true;
            s.insert(nums[i]);
        }
        return false;
    }

	// 41 / 41 test cases passed, but took too long.
	//Time Limit Exceeded
    /*bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k <= 0 || t < 0 || nums.empty()) return false;
        
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j <= k + i && j < nums.size(); ++j) {
                if (llabs((int64_t)nums[i] - (int64_t)nums[j]) <= t) 
                    return true;
            }
        }
        return false;
    }*/
};