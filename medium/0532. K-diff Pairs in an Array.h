// 532. K-diff Pairs in an Array

// Runtime: 56 ms, faster than 53.53% of C++ online submissions for K-diff Pairs in an Array.
// Memory Usage: 18.4 MB, less than 9.09% of C++ online submissions for K-diff Pairs in an Array.

// Time Complexity: O(nums.size()).
// Space Complexity: O(m.size()).

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        int ans = 0;
        unordered_map<int, int> m;
        for (int i : nums) ++m[i];
        for (auto& j : m) {
            if (k == 0) {
                if (j.second >= 2) ++ ans;
                continue;
            }
            auto it = m.find(j.first + k);
            if (it == m.end()) continue;
            ++ans;
        }
        return ans;
    }
};