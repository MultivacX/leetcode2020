// 1538. Guess the Majority in a Hidden Array
// https://leetcode.com/problems/guess-the-majority-in-a-hidden-array/

// Runtime: 536 ms, faster than 5.26% of C++ online submissions for Guess the Majority in a Hidden Array.
// Memory Usage: 31.2 MB, less than 57.89% of C++ online submissions for Guess the Majority in a Hidden Array.

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 *     int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int guessMajority(ArrayReader &reader) {
        const int N = reader.length();
        
        int cnt1 = 0, idx1 = -1;
        int cnt2 = 0, idx2 = -1;
        
        int p = reader.query(0, 1, 2, 3);
        int q = reader.query(0, 1, 2, 4);
        
        if (p == q) {
            // arr[3] == arr[4]
            cnt1 += 2, idx1 = 3;
        } else {
            // arr[3] != arr[4]
            cnt1 += 1, idx1 = 3;
            cnt2 += 1, idx2 = 4;
        }
        
        // arr[0], arr[1], arr[2]
        if (p == 4) {
            // arr[0] == arr[1] == arr[2] == arr[3]
            cnt1 += 3;
        } else if (p == 2) {
            int bit3 = 1 << 3, bit4 = 1 << 4;
            
            int t = reader.query(0, 1, 3, 4);
            if (p == t) bit4 |= 1 << 2; // arr[2] ?= arr[4]
            if (q == t) bit3 |= 1 << 2; // arr[2] ?= arr[3]
            
            t = reader.query(0, 2, 3, 4);
            if (p == t) bit4 |= 1 << 1; // arr[1] ?= arr[4]
            if (q == t) bit3 |= 1 << 1; // arr[1] ?= arr[3]
            
            t = reader.query(1, 2, 3, 4);
            if (p == t) bit4 |= 1 << 0; // arr[0] ?= arr[4]
            if (q == t) bit3 |= 1 << 0; // arr[0] ?= arr[3]
            
            // cout << bitset<5>(bit3) << endl;
            // cout << bitset<5>(bit4) << endl;
            
            if (p == q) {
                // arr[3] == arr[4]
                int bits = bit3 | bit4;
                for (int i = 0; i < 3; ++i) {
                    if (bits & (1 << i)) cnt1 += 1;
                    else cnt2 += 1, idx2 = i;
                }
            } else {
                for (int i = 0; i < 3; ++i) {
                    if (bit3 & (1 << i)) cnt1 += 1;
                    else cnt2 += 1, idx2 = i;
                }
            }
        } else {
            // 0 <= x, y, z <= 2
            // arr[x] == arr[3]
            // arr[y] == arr[z] 
            cnt1 += 1, cnt2 += 2;
        }
        
        for (int i = 5; i < N; ++i) {
            int t = reader.query(0, 1, 2, i);
            if (p == t) cnt1 += 1;
            else cnt2 += 1, idx2 = i;
        }
        
        if (cnt1 == cnt2) return -1;
        return cnt1 > cnt2 ? idx1 : idx2;
    }
};