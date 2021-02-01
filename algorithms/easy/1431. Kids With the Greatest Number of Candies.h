// 1431. Kids With the Greatest Number of Candies
// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

// Runtime: 4 ms, faster than 81.34% of C++ online submissions for Kids With the Greatest Number of Candies.
// Memory Usage: 9.3 MB, less than 58.81% of C++ online submissions for Kids With the Greatest Number of Candies.
    
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans(candies.size(), false);
        int g = *max_element(begin(candies), end(candies));
        for (int i = 0; i < candies.size(); ++i) 
            ans[i] = candies[i] + extraCandies >= g;
        return ans;
    }
};