// 1358. Number of Substrings Containing All Three Characters

// Runtime: 28 ms, faster than 59.29% of C++ online submissions for Number of Substrings Containing All Three Characters.
// Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Number of Substrings Containing All Three Characters.

class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt_a = 0;
        int cnt_b = 0;
        int cnt_c = 0;
        int cnt = 0;
        int begin = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'a') ++cnt_a;
            else if (s[i] == 'b') ++cnt_b;
            else ++cnt_c;
            
            while (cnt_a > 0 && cnt_b > 0 && cnt_c > 0) {
                // [begin, i][i + 1, N]
                cnt += s.length() - i;
                if (s[begin] == 'a') --cnt_a;
                else if (s[begin] == 'b') --cnt_b;
                else --cnt_c;
                
                ++begin;
            }
        }
        return cnt;
    }
};