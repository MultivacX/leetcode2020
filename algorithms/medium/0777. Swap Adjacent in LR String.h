// 777. Swap Adjacent in LR String

// Runtime: 20 ms, faster than 24.38% of C++ online submissions for Swap Adjacent in LR String.
// Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Swap Adjacent in LR String.

class Solution {
public:
    bool canTransform(string start, string end) {
        const int N = start.length();
        int i = 0;
        int j = 0;
        while (i < N && j < N) {
            while (i < N && start[i] == 'X') ++i;
            while (j < N && end[j] == 'X') ++j;
            if (i < N && j < N) {
                if (start[i] != end[j]) return false;
                if (start[i] == 'L' && i < j) return false;
                if (start[i] == 'R' && i > j) return false;
                ++i;
                ++j;
            }
        }
        while (i < N && start[i] == 'X') ++i;
        while (j < N && end[j] == 'X') ++j;
        return i == j;
    }
};