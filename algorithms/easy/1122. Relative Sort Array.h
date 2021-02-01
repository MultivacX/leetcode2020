// 1122. Relative Sort Array
// https://leetcode.com/problems/relative-sort-array/

// Runtime: 4 ms, faster than 87.65% of C++ online submissions for Relative Sort Array.
// Memory Usage: 8.3 MB, less than 41.09% of C++ online submissions for Relative Sort Array.
    
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> m;
        for (int i = 0; i < arr2.size(); ++i) m.emplace(arr2[i], i);
        for (int i : arr1) if (m.count(i) == 0) m.emplace(i, i + 1001);
        sort(begin(arr1), end(arr1), [&m](int l, int r){
            return m[l] < m[r];
        });
        return arr1;
    }
};