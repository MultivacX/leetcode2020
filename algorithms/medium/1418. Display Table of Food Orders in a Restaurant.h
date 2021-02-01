// 1418. Display Table of Food Orders in a Restaurant
// https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/

// Runtime: 160 ms, faster than 98.29% of C++ online submissions for Display Table of Food Orders in a Restaurant.
// Memory Usage: 39 MB, less than 7.14% of C++ online submissions for Display Table of Food Orders in a Restaurant.

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> foods;
        map<int, unordered_map<string, int>> tableNo_foodsCnt;
        for (const auto& o : orders) {
            ++tableNo_foodsCnt[stoi(o[1])][o[2]];
            foods.insert(o[2]);
        }
        const int M = 1 + tableNo_foodsCnt.size();
        const int N = 1 + foods.size();
        vector<vector<string>> ans(M, vector<string>(N));
        ans[0][0] = "Table";
        auto it = foods.begin();
        for (int j = 1; j < N; ++j, ++it) 
            ans[0][j] = *it;
        auto itTableNo = tableNo_foodsCnt.begin();
        for (int i = 1; i < M; ++i, ++itTableNo) {
            ans[i][0] = to_string(itTableNo->first);
            for (int j = 1; j < N; ++j) {
                auto itCnt = itTableNo->second.find(ans[0][j]);
                ans[i][j] = itCnt == itTableNo->second.end() ? "0" : to_string(itCnt->second);
            }
        }
        return ans;
    }
};