// 1061. Lexicographically Smallest Equivalent String
// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Lexicographically Smallest Equivalent String.
// Memory Usage: 6.8 MB, less than 92.31% of C++ online submissions for Lexicographically Smallest Equivalent String.
    
class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
        vector<int> parents(26, -1);
        for (int i = 0; i < 26; ++i)
            parents[i] = i;
        for (int j = 0; j < A.size(); ++j) {
            int a = A[j] - 'a';
            int b = B[j] - 'a';
            if (parents[a] == parents[b])
                continue;
            int p = min(parents[a], parents[b]);
            int q = max(parents[a], parents[b]);
            for (int i = 0; i < 26; ++i)
                if (parents[i] == q)
                    parents[i] = p;
        }
        string T(S);
        for (char& c : T)
            c = parents[c - 'a'] + 'a';
        return T;
    }
};