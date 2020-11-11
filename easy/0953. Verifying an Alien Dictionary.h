// 953. Verifying an Alien Dictionary
// https://leetcode.com/problems/verifying-an-alien-dictionary/

// Runtime: 8 ms, faster than 66.68% of C++ online submissions for Verifying an Alien Dictionary.
// Memory Usage: 10 MB, less than 93.11% of C++ online submissions for Verifying an Alien Dictionary.

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<int, int> m;
        for (int i = 0; i < 26; ++i)
            m[order[i]] = i;
        for (int i = 1; i < words.size(); ++i) {
            const int M = words[i - 1].size();
            const int N = words[i].size();
            bool equal = true;
            for (int j = 0; j < min(M, N); ++j) {
                if (m[words[i - 1][j]] > m[words[i][j]]) return false;
                if (m[words[i - 1][j]] < m[words[i][j]]) { equal = false; break; }
                if (m[words[i - 1][j]] == m[words[i][j]]) continue;
            }
            if (equal && M > N) return false;
        }
        return true;
    }
};