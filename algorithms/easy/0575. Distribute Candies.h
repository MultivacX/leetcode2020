// 575. Distribute Candies
// https://leetcode.com/problems/distribute-candies/

// Runtime: 448 ms, faster than 88.95% of C++ online submissions for Distribute Candies.
// Memory Usage: 110.7 MB, less than 76.73% of C++ online submissions for Distribute Candies.
    
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s(begin(candyType), end(candyType));
        return min(s.size(), candyType.size() >> 1);
    }
};