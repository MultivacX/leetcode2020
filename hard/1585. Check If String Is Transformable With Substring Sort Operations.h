// 1585. Check If String Is Transformable With Substring Sort Operations
// https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations/

// Runtime: 84 ms, faster than 98.46% of C++ online submissions for Check If String Is Transformable With Substring Sort Operations.
// Memory Usage: 23 MB, less than 5.05% of C++ online submissions for Check If String Is Transformable With Substring Sort Operations.

class Solution {
public:
    bool isTransformable(string s, string t) {
        const int N = s.length();
        vector<vector<int>> indexes(10);
        for (int i = N - 1; i >= 0; --i) 
            indexes[s[i] - '0'].push_back(i);
        for (int i = 0; i < N; ++i) {
            int y = t[i] - '0';
            if (indexes[y].empty()) return false;
            
            int j = indexes[y].back();
            for (int x = y - 1; x >= 0; --x) {
                for (int k = (int)indexes[x].size() - 1; k >= 0 && indexes[x][k] < j; --k) {
                    return false;
                }
            }
            indexes[y].pop_back();
        }
        return true;
    }
};