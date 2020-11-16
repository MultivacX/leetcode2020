// 1419. Minimum Number of Frogs Croaking
// https://leetcode.com/problems/minimum-number-of-frogs-croaking/

// Runtime: 92 ms, faster than 36.23% of C++ online submissions for Minimum Number of Frogs Croaking.
// Memory Usage: 9.8 MB, less than 13.65% of C++ online submissions for Minimum Number of Frogs Croaking.

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int ans = 0;
        unordered_map<char, int> m{{'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}};
        vector<int> croaks(5, 0);
        for (auto c : croakOfFrogs) {
            ++croaks[m[c]];
            for (int i = 0; i < 4; ++i) 
                if (croaks[i] < croaks[i + 1]) return -1;
            ans = max(ans, croaks[0]);
            for (int i = 0; i < 5; ++i) croaks[i] -= croaks[4];
            // for (int i : croaks) cout << i; cout << endl;
        }
        for (int i : croaks) if (i > 0) return -1;
        return ans ? ans : -1;
    }
};