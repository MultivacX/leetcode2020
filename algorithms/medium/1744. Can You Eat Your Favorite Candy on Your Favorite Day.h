// 1744. Can You Eat Your Favorite Candy on Your Favorite Day?
// https://leetcode.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/

// Runtime: 324 ms, faster than 80.00% of C++ online submissions for Can You Eat Your Favorite Candy on Your Favorite Day?.
// Memory Usage: 120.8 MB, less than 80.00% of C++ online submissions for Can You Eat Your Favorite Candy on Your Favorite Day?.

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        const int M = candiesCount.size();
        const int N = queries.size();
        
        vector<int64_t> presums(M);
        presums[0] = candiesCount[0];
        for (int i = 1; i < M; ++i)
            presums[i] = presums[i - 1] + candiesCount[i];
        
        vector<bool> ans(N);
        for (int i = 0; i < N; ++i) {
            int favoriteType = queries[i][0];
            int64_t favoriteDay = queries[i][1];
            int64_t dailyCap = queries[i][2];
            
            int64_t candies = (favoriteType == 0 ? 0 : presums[favoriteType - 1]) + 1;
            int64_t minCandies = favoriteDay * 1 + 1;
            int64_t maxCandies = favoriteDay * dailyCap + dailyCap;
            
            int64_t remain = candiesCount[favoriteType] - 1;
            
            if (candies - minCandies + remain < 0)
                continue;
            
            if (candies > maxCandies) 
                continue;
            
            ans[i] = true;
        }
        return ans;
    }
};