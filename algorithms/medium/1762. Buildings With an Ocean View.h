// 1762. Buildings With an Ocean View
// https://leetcode.com/problems/buildings-with-an-ocean-view/

// Runtime: 128 ms, faster than 100.00% of C++ online submissions for Buildings With an Ocean View.
// Memory Usage: 68.7 MB, less than 100.00% of C++ online submissions for Buildings With an Ocean View.
    
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        const int n = heights.size();
        vector<int> ans;
        for (int i = n - 1, h = 0; i >= 0; --i) {
            if (h < heights[i]) {
                ans.push_back(i);
                h = heights[i];
            }
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};