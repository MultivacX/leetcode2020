// 609. Find Duplicate File in System

// Runtime: 184 ms, faster than 39.41% of C++ online submissions for Find Duplicate File in System.
// Memory Usage: 48.1 MB, less than 66.67% of C++ online submissions for Find Duplicate File in System.

// Time Complexity: O(count(files)).
// Space Complexity: O(count(files)).

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        for (const string& p : paths) {
            vector<string> files;
            int i = 0;
            int l = 0;
            for (int j = 0; j < p.length(); ++j) {
                if (p[j] == '(') {
                    l = j;
                } else if (p[j] == ' ') {
                    if (l > i) {
                        files.emplace_back(files.empty() ? p.substr(i, l - i) : files.front() + "/" + p.substr(i, l - i));
                        m[p.substr(l + 1, j - 2 - l)].emplace_back(files.back());
                        l = 0;
                    } else {
                        files.emplace_back(files.empty() ? p.substr(i, j - i) : files.front() + "/" + p.substr(i, j - i));
                    }
                    i = j + 1;
                } else if (j + 1 == p.length()) {
                    if (l > i) {
                        files.emplace_back(files.empty() ? p.substr(i, l - i) : files.front() + "/" + p.substr(i, l - i));
                        m[p.substr(l + 1, j - 1 - l)].emplace_back(files.back());
                        l = 0;
                    } else {
                        files.emplace_back(files.empty() ? p.substr(i) : files.front() + "/" + p.substr(i));
                    }
                }
            }
        }
        vector<vector<string>> ans;
        for (auto it : m) if (it.second.size() > 1) ans.emplace_back(it.second);
        return ans;
    }
};