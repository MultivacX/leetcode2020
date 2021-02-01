// 1228. Missing Number In Arithmetic Progression
// https://leetcode.com/problems/missing-number-in-arithmetic-progression/

// Runtime: 8 ms, faster than 57.36% of C++ online submissions for Missing Number In Arithmetic Progression.
// Memory Usage: 8.5 MB, less than 58.91% of C++ online submissions for Missing Number In Arithmetic Progression.
    
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        const int N = arr.size();
        int removed = -1;
        for (int i = 2, x = arr[1] - arr[0]; i < N && removed < 0; ++i) {
            int y = arr[i] - arr[i - 1];
            if (x == y) continue;
            if (abs(x) > abs(y)) return arr[0] + y;
            else return arr[i - 1] + x;
        }
        return removed == -1 ? arr[0] : removed;
    }
};