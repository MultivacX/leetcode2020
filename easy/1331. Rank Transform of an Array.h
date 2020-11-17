// 1331. Rank Transform of an Array
// https://leetcode.com/problems/rank-transform-of-an-array/

// Runtime: 244 ms, faster than 43.37% of C++ online submissions for Rank Transform of an Array.
// Memory Usage: 48.4 MB, less than 5.97% of C++ online submissions for Rank Transform of an Array.

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, vector<int>> ranks;
        for (int i = 0; i < arr.size(); ++i) 
            ranks[arr[i]].push_back(i);
        vector<int> ans(arr.size());
        int rank = 1;
        for (const auto& it : ranks) {
            for (int i : it.second) 
                ans[i] = rank;
            ++rank;
        }
        return ans;
    }
};