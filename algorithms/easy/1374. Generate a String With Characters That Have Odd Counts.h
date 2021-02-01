// 1374. Generate a String With Characters That Have Odd Counts
// https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Generate a String With Characters That Have Odd Counts.
// Memory Usage: 6.6 MB, less than 32.92% of C++ online submissions for Generate a String With Characters That Have Odd Counts.
    
class Solution {
public:
    string generateTheString(int n) {
        return n & 1 ? string(n, 'a') : "a" + string(n - 1, 'b');
    }
};