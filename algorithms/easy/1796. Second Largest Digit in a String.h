// 1796. Second Largest Digit in a String
// https://leetcode.com/problems/second-largest-digit-in-a-string/

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Second Largest Digit in a String.
// Memory Usage: 6.7 MB, less than 100.00% of C++ online submissions for Second Largest Digit in a String.
    
class Solution {
public:
    int secondHighest(string s) {
        vector<int> cnt(10);
        for (char c : s) 
            if (isdigit(c)) 
                ++cnt[c - '0'];    
        
        for (int i = 9, foundMax = 0; i >= 0; --i) {
            if (cnt[i] == 0) continue;
            if (foundMax == 0) foundMax = 1;
            else return i;
        }
        return -1;
    }
};