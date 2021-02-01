// 789. Escape The Ghosts

// Runtime: 24 ms, faster than 23.10% of C++ online submissions for Escape The Ghosts.
// Memory Usage: 10.4 MB, less than 50.00% of C++ online submissions for Escape The Ghosts.

// Time Complexity: O(ghosts.size()).
// Space Complexity: O(1).

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dist = abs(target[0]) + abs(target[1]);
        for (const auto& g : ghosts)
            if (abs(target[0] - g[0]) + abs(target[1] - g[1]) <= dist)
                return false;
        return true;
    }
};