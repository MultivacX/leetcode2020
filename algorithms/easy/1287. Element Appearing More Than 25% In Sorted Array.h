// 1287. Element Appearing More Than 25% In Sorted Array
// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/

// Runtime: 24 ms, faster than 61.65% of C++ online submissions for Element Appearing More Than 25% In Sorted Array.
// Memory Usage: 12.6 MB, less than 86.53% of C++ online submissions for Element Appearing More Than 25% In Sorted Array.
    
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        const int N = arr.size();
        int v = arr[0];
        int c = 1;
        for (int i = 1; i < N; ++i) {
            if (v == arr[i]) {
                if (4 * (++c) > N)
                    return v;
            } else {
                v = arr[i];
                c = 1;
            }
        }
        return v;
    }
};