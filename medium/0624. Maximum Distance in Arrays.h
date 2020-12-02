// 624. Maximum Distance in Arrays
// https://leetcode.com/problems/maximum-distance-in-arrays/

// Runtime: 48 ms, faster than 77.34% of C++ online submissions for Maximum Distance in Arrays.
// Memory Usage: 18.7 MB, less than 56.64% of C++ online submissions for Maximum Distance in Arrays.
    
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        int minv = arrays[0].front();
        int maxv = arrays[0].back();
        for (int i = 1; i < arrays.size(); ++i) {
            ans = max(ans, abs(arrays[i].back() - minv));
            ans = max(ans, abs(arrays[i].front() - maxv));
            minv = min(minv, arrays[i].front());
            maxv = max(maxv, arrays[i].back());
        }
        return ans;
    }
};