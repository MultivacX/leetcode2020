// 388. Longest Absolute File Path

// Runtime: 4 ms, faster than 22.29% of C++ online submissions for Longest Absolute File Path.
// Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Longest Absolute File Path.

// Time Complexity: O(N).
// Space Complexity: O(max(level)).

class Solution {
public:
    int lengthLongestPath(string input) {
        const int N = input.length();
        int ans = 0;
        vector<int> lens;
        int i = 0;
        while (i < N) {
            // level
            //   0   dir0
            //   0   dir1
            //   1       subdir1
            //   2           file1.ext
            //   2           subsubdir1
            //   1       subdir2
            //   2           subsubdir2
            //   3               file2.ext
            //   0   dir2
            int level = 0;
            int len = 0;
            int point = -1;
            while (i < N && input[i] != '\n') {                
                if (input[i] == '\t') ++level;
                else ++len;
                if (input[i] == '.') point = i;
                ++i;
            }
            // . is file
            // .x is file
            // x. is file
            // check . /*and extension*/
            if (point >= 0/* && i - point > 1*/) {
                // cout << point << " " << i << endl;
                ans = max(ans, (level > 0 ? lens[level - 1] + 1 : 0) + len);
            } else {
                // update len of path
                if (lens.empty()) lens.push_back(len);
                else if (lens.size() == level) lens.push_back(lens.back() + 1 + len);
                else lens[level] = (level > 0 ? lens[level - 1] + 1 : 0) + len;
            }
            
            // skip \n
            ++i;
        }
        return ans;
    }
};