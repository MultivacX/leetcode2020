// 1496. Path Crossing
// https://leetcode.com/problems/path-crossing/

// Runtime: 4 ms, faster than 71.32% of C++ online submissions for Path Crossing.
// Memory Usage: 7.4 MB, less than 9.30% of C++ online submissions for Path Crossing.

class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0;
        int y = 0;
        unordered_map<int, unordered_set<int>> m;
        m[x].insert(y);
        for (char c : path) {
            if (c == 'N') ++y;
            else if (c == 'S') --y;
            else if (c == 'E') ++x;
            else if (c == 'W') --x;
            
            if (m[x].count(y)) return true;
            m[x].insert(y);
        }
        return false;
    }
};