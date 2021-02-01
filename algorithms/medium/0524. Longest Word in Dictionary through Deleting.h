// 524. Longest Word in Dictionary through Deleting

// Runtime: 116 ms, faster than 41.79% of C++ online submissions for Longest Word in Dictionary through Deleting.
// Memory Usage: 15 MB, less than 100.00% of C++ online submissions for Longest Word in Dictionary through Deleting.

// Time Complexity: O(d.size() * M).
// Space Complexity: O(ans->length()).

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        const string* ans = nullptr;
        const int M = s.length();
        for (const auto& w : d) {
            int i = 0;
            const int N = w.length();
            int j = 0;
            while (i < M && j < N) if (s[i++] == w[j]) ++j;
            if (j == N) ans = !ans || ans->length() < w.length() || (ans->length() == w.length() && *ans > w) ? &w : ans;
        }
        return !ans ? "" : *ans;
    }
};