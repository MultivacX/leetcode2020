// 1598. Crawler Log Folder
// https://leetcode.com/problems/crawler-log-folder/

// Runtime: 12 ms, faster than 33.83% of C++ online submissions for Crawler Log Folder.
// Memory Usage: 10.5 MB, less than 96.78% of C++ online submissions for Crawler Log Folder.
    
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int step = 0;
        for (const string& s : logs) {
            if (s == "./") continue;
            if (s == "../") --step;
            else ++step;
            if (step < 0) step = 0;
        }
        return step;
    }
};