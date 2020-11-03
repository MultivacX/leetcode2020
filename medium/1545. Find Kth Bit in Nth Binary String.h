// 1545. Find Kth Bit in Nth Binary String
// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find Kth Bit in Nth Binary String.
// Memory Usage: 6.3 MB, less than 5.01% of C++ online submissions for Find Kth Bit in Nth Binary String.

class Solution {
    int find(int n, int k) {
        if (n == 1) return 0;
        
        int l = (1 << n) - 1;
        int m = (l >> 1) + 1;
        // printf("n:%d, k:%d, l:%d, m:%d\n", n, k, l, m);
        if (k == m) return 1;
        if (k < m) return find(n - 1, k);
        return find(n - 1, (l >> 1) - (k - m) + 1) == 0 ? 1 : 0;
    }
    
public:
    char findKthBit(int n, int k) {
        // cout << (int)pow(2, 20) - 1 << endl;
        return find(n, k) == 0 ? '0' : '1';
    }
};