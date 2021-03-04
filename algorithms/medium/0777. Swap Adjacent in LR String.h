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


class Solution {    
public:
    bool canTransform(string start, string end) {
        const int n = start.length();
        int i = 0;
        while (i < n) {
            if (start[i] == end[i]) {
                ++i;
            } else if (end[i] == 'X') {
                int j = i;
                while (j < n) {
                    if (start[j] == 'L')
                        return false;
                    if (start[j] == 'X') {
                        swap(start[i++], start[j]);
                        break;
                    }
                    if (++j == n) return false;
                }
            } else if (end[i] == 'L') {
                int j = i;
                while (j < n) {
                    if (start[j] == 'R')
                        return false;
                    if (start[j] == 'L') {
                        swap(start[i++], start[j]);
                        break;
                    }
                    if (++j == n) return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};


class Solution {    
public:
    bool canTransform(string start, string end) {
        const int n = start.length();
        int i = 0, j = 0;
        while (true) {
            while (i < n && start[i] == 'X') ++i;
            while (j < n && end[j] == 'X') ++j;
            if (i == n || j == n) return i == j;
            if (start[i] != end[j]) return false;
            
            if (start[i] == 'L' && i < j) return false;
            if (start[i] == 'R' && i > j) return false;
            ++i; ++j;
        }
        return true;
    }
};