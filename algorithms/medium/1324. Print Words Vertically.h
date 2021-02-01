// 1324. Print Words Vertically

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Print Words Vertically.
// Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for Print Words Vertically.

class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> v;
        int row = 0;
        int col = 0;
        for (char c : s) {
            if (c == ' ') {
                row = 0;
                ++col;
            } else {
                if (v.size() < row + 1) v.push_back("");
                while (v[row].length() < col) v[row].push_back(' ');
                v[row].push_back(c);
                ++row;
            }
        }
        return v;
    }
};