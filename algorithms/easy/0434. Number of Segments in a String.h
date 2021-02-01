// 434. Number of Segments in a String

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Segments in a String.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Number of Segments in a String.

class Solution {
public:
    int countSegments(string s) {
        const int N = s.length();
        int ans = 0;
        int i = 0;
        while (i < N) {
            while (i < N && s[i] == ' ') ++i;
            if (i < N) ++ans;
            while (i < N && s[i] != ' ') ++i;
        }
        return ans;
    }
};