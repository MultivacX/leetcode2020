// 1849. Splitting a String Into Descending Consecutive Values
// https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Splitting a String Into Descending Consecutive Values.
// Memory Usage: 6 MB, less than 49.60% of C++ online submissions for Splitting a String Into Descending Consecutive Values.
    
class Solution {
    bool check(const string& s, int start, uint64_t pre) {
        const int n = s.length();
        if (start >= n) return true;
        
        uint64_t cur = 0;
        for (int i = start; i < n; ++i) {
            cur = cur * 10 + s[i] - '0';
            if (pre <= cur) return false;
            if (pre - 1 == cur && check(s, i + 1, cur)) return true;
        }
        return false;        
    }
    
public:
    bool splitString(string s) {
        const int n = s.length();
        uint64_t first = 0;
        for (int i = 0; i + 1 < n; ++i) {
            first = first * 10 + s[i] - '0';
            if (first == 0) continue;
            if (check(s, i + 1, first)) return true;
        }
        return false;
    }
};