// 1282. Group the People Given the Group Size They Belong To
// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

// Runtime: 16 ms, faster than 96.17% of C++ online submissions for Group the People Given the Group Size They Belong To.
// Memory Usage: 13.2 MB, less than 11.26% of C++ online submissions for Group the People Given the Group Size They Belong To.

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        const int N = groupSizes.size();
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> cnts;
        for (int i = 0; i < N; ++i) {
            if (cnts[groupSizes[i]].size() + 1 == groupSizes[i]) {
                ans.push_back(cnts[groupSizes[i]]);
                ans.back().push_back(i);
                cnts[groupSizes[i]].clear();
            } else {
                cnts[groupSizes[i]].push_back(i);
            }
        }
        return ans;
    }
};