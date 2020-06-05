// 443. String Compression
// https://leetcode.com/problems/string-compression/

// Runtime: 4 ms, faster than 99.65% of C++ online submissions for String Compression.
// Memory Usage: 9.2 MB, less than 12.97% of C++ online submissions for String Compression.

class Solution {
public:
    int compress(vector<char>& chars) {
        const int N = chars.size();
        if (N == 1) return 1;
        
        int i = 0;
        int l = 0;
        int r = 0;
        
        while (r < N) {
            if (chars[l] == chars[r]) {
                if (r == N - 1) {
                    chars[i++] = chars[l];
                    int cnt = r - l + 1;
                    if (cnt != 1) {
                        string cs(to_string(cnt));
                        for (char n : cs) chars[i++] = n;
                    }
                }
                ++r;
            } else {
                chars[i++] = chars[l];
                int cnt = r - l;
                if (cnt != 1) {
                    string cs(to_string(cnt));
                    for (char n : cs) chars[i++] = n;
                }
                l = r;
            }
            
            // for (char c : chars) cout << c; cout << endl;
        }
        return i;
    }
};