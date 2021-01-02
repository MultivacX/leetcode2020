// 1133. Largest Unique Number
// https://leetcode.com/problems/largest-unique-number/

// Runtime: 12 ms, faster than 42.68% of C++ online submissions for Largest Unique Number.
// Memory Usage: 9.5 MB, less than 17.20% of C++ online submissions for Largest Unique Number.
    
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        unordered_map<int, int> m;
        for (int i : A) ++m[i];
        int ans = -1;
        for (const auto& it : m)
            if (it.second == 1 && it.first > ans)
                ans = it.first;
        return ans;
    }
};