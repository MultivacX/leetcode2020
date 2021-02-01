// 1502. Can Make Arithmetic Progression From Sequence
// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Can Make Arithmetic Progression From Sequence.
// Memory Usage: 9 MB, less than 93.26% of C++ online submissions for Can Make Arithmetic Progression From Sequence.
    
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(begin(arr), end(arr));
        for (int i = 2, d = arr[0] - arr[1]; i < arr.size(); ++i) 
            if (d != arr[i - 1] - arr[i])
                return false;
        return true;
    }
};