// 11. Container With Most Water

// Runtime: 16 ms, faster than 96.24% of C++ online submissions for Container With Most Water.
// Memory Usage: 9.8 MB, less than 84.54% of C++ online submissions for Container With Most Water.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            ans = max(ans, min(height[j], height[i]) * (j - i));
            if (height[i] < height[j]) ++i;
            else --j;
        }
        return ans;
    }
};