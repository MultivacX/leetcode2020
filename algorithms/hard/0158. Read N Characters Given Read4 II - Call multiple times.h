// 158. Read N Characters Given Read4 II - Call multiple times
// https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Read N Characters Given Read4 II - Call multiple times.
// Memory Usage: 6.9 MB, less than 40.82% of C++ online submissions for Read N Characters Given Read4 II - Call multiple times.
    
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
    int M = 0;
    int N = 0;
    queue<char> q;
    
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        N += n;
        if (M < N) {
            int i = 0;
            char buf4[4];
            while (true) {
                int cnt = read4(buf4);
                for (int j = 0; j < cnt; ++j)
                    q.push(buf4[j]);
                i += cnt;
                M += cnt;
                if (cnt < 4) break;
                if (i >= N) break;
            }
        }
        
        int ans = 0;
        while (n-- > 0 && !q.empty()) {
            buf[ans++] = q.front();
            q.pop();
        }
        return ans;
    }
};