// 748. Shortest Completing Word
// https://leetcode.com/problems/shortest-completing-word/

// Runtime: 76 ms, faster than 14.12% of C++ online submissions for Shortest Completing Word.
// Memory Usage: 21 MB, less than 14.12% of C++ online submissions for Shortest Completing Word.

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> lp;
        for (auto c : licensePlate) if (isalpha(c)) ++lp[tolower(c)];
        string* ans = nullptr;
        for (auto& w : words) {
            unordered_map<char, int> m;
            for (auto c : w) if (isalpha(c)) ++m[tolower(c)];
            bool b = true;
            for (auto it : lp) if (!m.count(it.first) || m[it.first] < it.second) { b = false; break; }
            if (b && (!ans || ans->length() > w.length())) ans = &w;
        }
        return *ans;
    }
};