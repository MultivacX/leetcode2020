// 1554. Strings Differ by One Character
// https://leetcode.com/problems/strings-differ-by-one-character/

// Runtime: 352 ms, faster than 85.00% of C++ online submissions for Strings Differ by One Character.
// Memory Usage: 148.4 MB, less than 48.75% of C++ online submissions for Strings Differ by One Character.

class Solution {
public:
    bool differByOne(vector<string>& dict) {
        unordered_set<string> s;
        for (string w : dict) {
            for (auto& c : w) {
                char t = c;
                c = '*';
                if (!s.insert(w).second)
                    return true;
                c = t;
            }
        }
        return false;
    }
};