// 71. Simplify Path

// Runtime: 16 ms, faster than 13.21% of C++ online submissions for Simplify Path.
// Memory Usage: 16.2 MB, less than 7.14% of C++ online submissions for Simplify Path.

// Runtime: O(N).
// Memory: O(N).

class Solution {
public:
    string simplifyPath(string path) {
        const int N = path.length();
        
        vector<string> v;
        int i = 0;
        while (i < N) {
            if (path[i] == '/') {
                if (v.empty() || v.back() != "/") v.push_back("/");
                ++i;
            }  else {
                string dir;
                while (i < N && path[i] != '/') {
                    dir += path[i];
                    ++i;
                }
                if (dir.length() == 1 && dir[0] == '.');
                else if (dir.length() == 2 && dir == "..") {
                    if (!v.empty()) v.pop_back();
                    if (!v.empty()) v.pop_back();
                }
                else if (!dir.empty()) v.push_back(dir);
            }
        }
        while (!v.empty() && v.back() == "/") v.pop_back();
        return accumulate(begin(v), end(v), v.empty() || v[0] != "/" ? string("/") : string{});
    }
};