// 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

// Runtime: 172 ms, faster than 57.19% of C++ online submissions for Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts.
// Memory Usage: 32.6 MB, less than 15.72% of C++ online submissions for Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts.
    
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(begin(horizontalCuts), end(horizontalCuts));
        int maxH = max(horizontalCuts.front(), h - horizontalCuts.back());
        for (int i = 1; i < horizontalCuts.size(); ++i) 
            maxH = max(maxH, horizontalCuts[i] - horizontalCuts[i - 1]);
        
        sort(begin(verticalCuts), end(verticalCuts));
        int maxW = max(verticalCuts.front(), w - verticalCuts.back());
        for (int i = 1; i < verticalCuts.size(); ++i) 
            maxW = max(maxW, verticalCuts[i] - verticalCuts[i - 1]);
        
        return (int64_t)maxH * (int64_t)maxW % 1000000007;
    }
};