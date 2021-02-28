// 277. Find the Celebrity
// https://leetcode.com/problems/find-the-celebrity/

// Runtime: 164 ms, faster than 36.51% of C++ online submissions for Find the Celebrity.
// Memory Usage: 9.8 MB, less than 84.57% of C++ online submissions for Find the Celebrity.
    
/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
    bool knowsSomeone(int n, int x) {
        for (int i = 0; i < n; ++i)
            if (x != i && knows(x, i))
                return true;
        return false;
    }
    
public:
    int findCelebrity(int n) {
        int x = -1;
        for (int i = 0; i < n; ++i) {
            if (!knowsSomeone(n, i)) {
                x = i;
                break;
            }
        }
        if (x == -1) return -1;
        
        for (int i = 0; i < n; ++i) 
            if (x != i && !knows(i, x))
                return -1;
        return x;
    }
};


class Solution {
public:
    int findCelebrity(int n) {
        int x = 0;
        for (int i = 1; i < n; ++i) 
            if (knows(x, i)) 
                x = i;
        
        for (int i = 0; i < n; ++i) 
            if (x != i && (!knows(i, x) || knows(x, i)))
                return -1;
        return x;
    }
};