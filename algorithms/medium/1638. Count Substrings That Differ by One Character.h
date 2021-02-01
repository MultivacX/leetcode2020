// 1638. Count Substrings That Differ by One Character
// https://leetcode.com/problems/count-substrings-that-differ-by-one-character/

// Runtime: 212 ms, faster than 28.10% of C++ online submissions for Count Substrings That Differ by One Character.
// Memory Usage: 44.8 MB, less than 18.21% of C++ online submissions for Count Substrings That Differ by One Character.

class Solution {
public:
    int countSubstrings(string s, string t) {
        const int M = s.length();
        const int N = t.length();
        int ans = 0;
        unordered_map<int, unordered_set<int>> same, diff;
        for (int i = 0; i < M; ++i) 
            for (int j = 0; j < N; ++j) 
                if (s[i] == t[j]) same[i].insert(j);
                else diff[i].insert(j), ++ans;

        unordered_map<int, unordered_set<int>> next_same, next_diff;
        for (int L = 2; L <= M; ++L) {
            next_same.clear();
            next_diff.clear();
            
            for (auto it : same) {
                int i = it.first;
                if (++i >= M) continue;
                for (int j : it.second) {
                    if (++j >= N) continue;
                    if (s[i] == t[j]) next_same[i].insert(j);
                    else next_diff[i].insert(j), ++ans;
                }
            }
            
            for (auto it : diff) {
                int i = it.first;
                if (++i >= M) continue;
                for (int j : it.second) {
                    if (++j >= N) continue;
                    if (s[i] == t[j]) next_diff[i].insert(j), ++ans;
                }
            }
            
            same = next_same;
            diff = next_diff;
        }
        return ans;
    }
};