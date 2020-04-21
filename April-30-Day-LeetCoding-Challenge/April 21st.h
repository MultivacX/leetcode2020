// the 30-Day LeetCoding Challenge for the month of April
// April 21st, 2020

// Leftmost Column with at Least a One

// Runtime: 12 ms
// Memory Usage: 8 MB

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto d = binaryMatrix.dimensions();
        const int n = d[0]; // x = [0, n - 1]
        const int m = d[1]; // y = [0, m - 1]

        int begin = 0;
        int end = m;
        int ans = m;
        while (begin < end) {
            int y = begin + ((end - begin) >> 1);
            bool find = false;
            for (int x = 0; x < n && !find; ++x) 
                if (binaryMatrix.get(x, y) == 1)
                    find = true;
            if (find) {
                ans = y;
                end = y;
            } else {
                begin = y + 1;
            }
        }
        return ans == m ? -1 : ans;
    }
};