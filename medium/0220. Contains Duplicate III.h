// 220. Contains Duplicate III

class Solution {
public:
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