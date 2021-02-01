// 1533. Find the Index of the Large Integer
// https://leetcode.com/problems/find-the-index-of-the-large-integer/

// Runtime: 136 ms, faster than 73.26% of C++ online submissions for Find the Index of the Large Integer.
// Memory Usage: 39.9 MB, less than 29.07% of C++ online submissions for Find the Index of the Large Integer.
    
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
    int ans = -1;
    
    void find(ArrayReader &reader, int L, int R) {
        if (L == R) ans = L;
        if (ans >= 0 || L > R) return;
        int N = R - L + 1;
        if (N % 2 == 0) {
            int l = L, r = L + N / 2 - 1, x = L + N / 2, y = R;
            // printf("0: [%d, %d] <> [%d, %d]\n", l, r, x, y);
            
            int c = reader.compareSub(l, r, x, y);
            if (c == 1) find(reader, l, r);
            else if (c == -1) find(reader, x, y);
        } else {
            int l = L, r = L + N / 2 - 1, x = L + N / 2 + 1, y = R;
            int m = L + N / 2;
            // printf("1: [%d, %d] <%d> [%d, %d]\n", l, r, m, x, y);
            
            int c = reader.compareSub(l, r, x, y);
            if (c == 0) ans = m;
            else if (c == 1) find(reader, l, r);
            else if (c == -1) find(reader, x, y);
        }
    }
    
public:
    int getIndex(ArrayReader &reader) {
        find(reader, 0, reader.length() - 1);
        return ans;
    }
};