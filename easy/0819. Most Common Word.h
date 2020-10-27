// 819. Most Common Word
// https://leetcode.com/problems/most-common-word/

// Runtime: 4 ms, faster than 98.44% of C++ online submissions for Most Common Word.
// Memory Usage: 8.1 MB, less than 5.60% of C++ online submissions for Most Common Word.

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> banned_;
        for (auto s : banned) banned_.insert(s);
        unordered_map<string, int> m;
        string s;
        for (int i = 0; i < paragraph.length(); ++i) {
            if (isalpha(paragraph[i])) s += tolower(paragraph[i]);
            if (!s.empty() && (!isalpha(paragraph[i]) || i + 1 == paragraph.length())) {
                if (banned_.count(s) == 0) ++m[s];
                s = "";
            }
        }
        string ans;
        int cnt = 0;
        for (auto it : m) {
            if (cnt < it.second) {
                cnt = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};