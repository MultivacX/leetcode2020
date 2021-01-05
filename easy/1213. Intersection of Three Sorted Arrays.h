// 1213. Intersection of Three Sorted Arrays
// https://leetcode.com/problems/intersection-of-three-sorted-arrays/

// Runtime: 12 ms, faster than 97.16% of C++ online submissions for Intersection of Three Sorted Arrays.
// Memory Usage: 12.1 MB, less than 77.68% of C++ online submissions for Intersection of Three Sorted Arrays.
    
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        const int n1 = arr1.size(), n2 = arr2.size(), n3 = arr3.size();
        int i1 = 0, i2 = 0, i3 = 0;
        while (i1 < n1 && i2 < n2 && i3 < n3) {
            if (arr1[i1] == arr2[i2] && arr2[i2] == arr3[i3]) {
                ans.push_back(arr1[i1]);
                ++i1, ++i2, ++i3;
            } else {
                int mv = min(arr1[i1], min(arr2[i2], arr3[i3]));
                if (mv == arr1[i1]) ++i1;
                if (mv == arr2[i2]) ++i2;
                if (mv == arr3[i3]) ++i3;
            }
        }
        return ans;
    }
};