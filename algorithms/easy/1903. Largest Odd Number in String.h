// 1903. Largest Odd Number in String
// https://leetcode.com/problems/largest-odd-number-in-string/

// Runtime: 32 ms, faster than 40.00% of C++ online submissions for Largest Odd Number in String.
// Memory Usage: 13.8 MB, less than 20.00% of C++ online submissions for Largest Odd Number in String.
    
class Solution {
public:
    string largestOddNumber(string num) {
        while (!num.empty() && ((num.back() - '0') & 1) == 0)
            num.pop_back();
        return num;
    }
};