// 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

// Runtime: 36 ms, faster than 95.59% of C++ online submissions for Partitioning Into Minimum Number Of Deci-Binary Numbers.
// Memory Usage: 13.9 MB, less than 54.38% of C++ online submissions for Partitioning Into Minimum Number Of Deci-Binary Numbers.
    
class Solution {
public:
    int minPartitions(string n) {
        const int N = n.length();
        int ans = 0;
        for (int i = N - 1; i >= 0; --i) {
            int v = n[i] - '0';
            if (ans < v) ans = v;
        }
        return ans;
    }
};