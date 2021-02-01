// 1243. Array Transformation
// https://leetcode.com/problems/array-transformation/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Array Transformation.
// Memory Usage: 7.6 MB, less than 17.46% of C++ online submissions for Array Transformation.
    
class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        const int N = arr.size();
        vector<int> tmp(arr);
        while (true) {
            vector<int> tmp(arr);
            bool changed = false;
            for (int i = 1; i + 1 < N; ++i) {
                if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
                    --tmp[i];
                    changed = true;
                } else if (arr[i - 1] > arr[i] && arr[i] < arr[i + 1]) {
                    ++tmp[i];
                    changed = true;
                }
            }
            if (!changed) break;
            arr = tmp;
        }
        return arr;
    }
};