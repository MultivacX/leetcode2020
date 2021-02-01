// 384. Shuffle an Array

// Runtime: 200 ms, faster than 88.38% of C++ online submissions for Shuffle an Array.
// Memory Usage: 30.3 MB, less than 57.14% of C++ online submissions for Shuffle an Array.

class Solution {
public:
    Solution(vector<int>& nums) : original(nums), n(nums.size()) {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ans = original;
        for (int i = 0; i < n - 1; ++i) {
            int j = rand() % (n - i) + i;
            swap(ans[i], ans[j]);
        }
        return ans;
    }
    
    vector<int> original;
    const int n;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */