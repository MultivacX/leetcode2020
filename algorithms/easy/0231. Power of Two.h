// 231. Power of Two

// Runtime: 4 ms, faster than 34.67% of C++ online submissions for Power of Two.
// Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Power of Two.

class Solution {
public:
    bool isPowerOfTwo(int n) {        
        if (n > 0) {
            int i = 0;
            while (i <= 30 && ((1 << i) & n) == 0) ++i;
            ++i;
            while (i <= 30 && ((1 << i) & n) == 0) ++i;
            return i > 30;
        }
        
        return false;
    }
};

// Time Complexity: O(1).
// Space Complexity: O(1).

class Solution {
public:
    bool isPowerOfTwo(int n) { 
        return n > 0 && !(n & (n - 1));
    }
};