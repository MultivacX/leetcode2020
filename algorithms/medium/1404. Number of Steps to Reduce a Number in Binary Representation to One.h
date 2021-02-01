// 1404. Number of Steps to Reduce a Number in Binary Representation to One

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Steps to Reduce a Number in Binary Representation to One.
// Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for Number of Steps to Reduce a Number in Binary Representation to One.

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int idx = s.length() - 1;
        int carry = 0;
        while (idx >= 0) {
            if (s[idx] == '0') {
                if (carry == 0) {
                    // divide it by 2
                    --idx;
                    ++steps;
                } else {
                    s[idx] = '1';
                    carry = 0;
                }
            } else {
                if (carry == 0) {
                    if (idx == 0) return steps;
                    
                    // add 1
                    carry = 1;
                    // s[idx] = '0';
                    ++steps;
                } 
                
                // divide it by 2
                --idx;
                ++steps;
            }
        }
        return steps;
    }
};