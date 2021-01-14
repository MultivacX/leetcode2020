// 1385. Find the Distance Value Between Two Arrays
// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/

// Runtime: 12 ms, faster than 97.76% of C++ online submissions for Find the Distance Value Between Two Arrays.
// Memory Usage: 13.2 MB, less than 100.00% of C++ online submissions for Find the Distance Value Between Two Arrays.
    
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(begin(arr2), end(arr2));
        int ans = 0;
        for (int v : arr1) {
            auto i = lower_bound(begin(arr2), end(arr2), v - d);
            auto j = upper_bound(begin(arr2), end(arr2), v + d);
            if (i == j) ++ans;
        }
        return ans;
    }
};