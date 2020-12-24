// 157. Read N Characters Given Read4
// https://leetcode.com/problems/read-n-characters-given-read4/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Read N Characters Given Read4.
// Memory Usage: 6.6 MB, less than 58.32% of C++ online submissions for Read N Characters Given Read4.
    
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int i = 0;
        while (i < n) {
            char buf4[4];
            int cnt = read4(buf4);
            for (int j = 0; j < cnt && i < n; ++j, ++i)
                buf[i] = buf4[j];
            if (cnt < 4) break;
        }
        return i;
    }
};