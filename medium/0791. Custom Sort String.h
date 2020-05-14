// 791. Custom Sort String

// Runtime: 8 ms, faster than 10.77% of C++ online submissions for Custom Sort String.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Custom Sort String.

// Time Complexity: O(n * lg(n)). n = T.length().
// Space Complexity: O(1).

class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, char> m;
        unordered_set<char> characters;
        for (char c = 'a'; c <= 'z'; ++ c) characters.insert(c);
        char c = 'a';
        for (const char& s : S) {
            m[s] = c++;
            characters.erase(s);
        }
        while (!characters.empty()) {
            m[*characters.begin()] = c++;
            characters.erase(characters.begin());
        }
        sort(begin(T), end(T), [&](const char& l, const char& r){ return m[l] < m[r]; });
        return T;
    }
};