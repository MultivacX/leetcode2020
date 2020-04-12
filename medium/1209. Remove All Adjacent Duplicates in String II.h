// 1209. Remove All Adjacent Duplicates in String II

// Runtime: 32 ms, faster than 27.13% of C++ online submissions for Remove All Adjacent Duplicates in String II.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Remove All Adjacent Duplicates in String II.

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> v;
        for (char& c : s) {
            if (v.empty() || v.back().first != c) {
                v.emplace_back(c, 1);
            } else if (v.back().first == c) {
                int cnt = ++v.back().second;
                if (cnt % k == 0) v.pop_back();
            }
        }
        string t;
        for (const auto& p : v) t.append(p.second, p.first);
        return t;
    }
};