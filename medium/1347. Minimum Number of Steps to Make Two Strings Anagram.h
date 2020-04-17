// 1347. Minimum Number of Steps to Make Two Strings Anagram

// Runtime: 92 ms, faster than 61.90% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram.
// Memory Usage: 16.5 MB, less than 100.00% of C++ online submissions for Minimum Number of Steps to Make Two Strings Anagram.

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> v(26, 0);
        for (const char& c : s) ++v[c - 'a'];
        for (const char& c : t) --v[c - 'a'];
        // for (int i : v) cout << i << ", ";
        int steps = 0;
        for (int i : v) if (i > 0) steps += i;
        return steps;
    }
};