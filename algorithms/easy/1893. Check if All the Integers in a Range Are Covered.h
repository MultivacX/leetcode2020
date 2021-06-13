// 1893. Check if All the Integers in a Range Are Covered
// https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check if All the Integers in a Range Are Covered.
// Memory Usage: 8.9 MB, less than 16.67% of C++ online submissions for Check if All the Integers in a Range Are Covered.
    
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        map<int, int> m;
        for (const auto& r : ranges)
            ++m[r[0]], --m[r[1] + 1];
        
        int start = -1;
        int k = 0;
        for (const auto& [val, cnt] : m) {
            if (start == -1) {
                start = val;
                k = cnt;
                continue;
            } 
            
            k += cnt;
            if (k == 0) {
                // [start, val)
                if (start <= left && right < val)
                    return true;
                start = -1;
            }
        }
        
        return false;
    }
};