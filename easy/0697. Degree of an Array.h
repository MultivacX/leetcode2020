// 697. Degree of an Array

// Runtime: 52 ms, faster than 38.20% of C++ online submissions for Degree of an Array.
// Memory Usage: 13.8 MB, less than 72.73% of C++ online submissions for Degree of an Array.

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int degree = 1;
        // <num, <i, j, degree>>
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; ++i) {
            if (m.count(nums[i]) == 0) {
                m.insert({nums[i], {i, i, 1}});
            } else {
                m[nums[i]][1] = i;
                ++m[nums[i]][2];
                degree = max(degree, m[nums[i]][2]);
            }
        }
        if (degree == 1) return 1;
                         
        int len = INT_MAX;
        for (auto it : m) {
            if (it.second[2] != degree) continue;
            int l = it.second[1] - it.second[0] + 1;
            len = min(len, l);
        }
        return len;
    }
};