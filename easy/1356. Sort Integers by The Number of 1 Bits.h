// 1356. Sort Integers by The Number of 1 Bits
// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

// Runtime: 68 ms, faster than 5.37% of C++ online submissions for Sort Integers by The Number of 1 Bits.
// Memory Usage: 11.9 MB, less than 5.83% of C++ online submissions for Sort Integers by The Number of 1 Bits.
    
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int a : arr) {
            int cnt = 0;
            for (int i = 0; i <= 13; ++i)
                if (a & (1 << i)) ++cnt;
            m[a] = cnt;
        }
        sort(begin(arr), end(arr), [&](int l, int r){ return m[l] < m[r] || (m[l] == m[r] && l < r); });
        return arr;
    }
};