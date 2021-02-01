// 14. Longest Common Prefix

// Runtime: 8 ms, faster than 38.03% of C++ online submissions for Longest Common Prefix.
// Memory Usage: 9.3 MB, less than 6.45% of C++ online submissions for Longest Common Prefix.

// Time Complexity: O(M*min(strs[j].size())).
// Space Complexity: O(prefix.length()).

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const int M = strs.size();
        if (M == 0) return "";
        if (M == 1) return strs[0];
        
        string prefix;
        int i = 0;
        while (i >= 0) {
            int j = 0;
            int N = strs[j].size();
            if (i >= N) break;
            
            char c = strs[j][i];
            for (j = 1; j < M; ++j) {
                const int N = strs[j].size();
                if (i > N || c != strs[j][i]) break;
            }
            if (j != M) break;
            
            prefix += c;
            ++i;
        }
        return prefix;
    }
};