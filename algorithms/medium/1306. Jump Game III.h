// 1306. Jump Game III

// Runtime: 48 ms, faster than 93.41% of C++ online submissions for Jump Game III.
// Memory Usage: 12.2 MB, less than 100.00% of C++ online submissions for Jump Game III.

class Solution {
public:
    bool canReach(vector<int>& arr, int i) {
        if (i < 0 || i >= arr.size()) return false;
        if (arr[i] < 0) return false;
        if (arr[i] == 0) return true;
        arr[i] *= -1;
        return canReach(arr, i + arr[i]) || canReach(arr, i - arr[i]);
    }
};