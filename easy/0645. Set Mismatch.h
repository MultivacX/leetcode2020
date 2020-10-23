// 645. Set Mismatch
// https://leetcode.com/problems/set-mismatch/

// Runtime: 48 ms, faster than 87.60% of C++ online submissions for Set Mismatch.
// Memory Usage: 22.8 MB, less than 13.28% of C++ online submissions for Set Mismatch.

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const auto N = nums.size();
        vector<int> visited(N + 1, 0);
        for (int i : nums) ++visited[i];
        vector<int> errors(2);
        for (int i = 1; i <= N; ++i)
            if (visited[i] == 2) errors[0] = i;
            else if (visited[i] == 0) errors[1] = i;    
        return errors;
    }
};