// 771. Jewels and Stones
// https://leetcode.com/problems/jewels-and-stones/

// Runtime: 4 ms, faster than 50.12% of C++ online submissions for Jewels and Stones.
// Memory Usage: 6.9 MB, less than 16.60% of C++ online submissions for Jewels and Stones.
    
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> j(begin(jewels), end(jewels));
        int num = 0;
        for (char c : stones)
            if (j.count(c))
                ++num;
        return num;
    }
};


class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<bool> isJewels(128, false);
        for (char c : jewels) 
            isJewels[c] = true;
        
        int num = 0;
        for (char c : stones)
            if (isJewels[c])
                ++num;
        return num;
    }
};