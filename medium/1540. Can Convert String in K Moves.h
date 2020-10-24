// 1540. Can Convert String in K Moves
// https://leetcode.com/problems/can-convert-string-in-k-moves/

// Runtime: 72 ms, faster than 84.27% of C++ online submissions for Can Convert String in K Moves.
// Memory Usage: 18.3 MB, less than 5.06% of C++ online submissions for Can Convert String in K Moves.

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        const int M = s.length();
        const int N = t.length();
        if (M != N) return false;
        // unordered_set<int> used;
        vector<int> used(26, 0);
        for (int i = 0; i < M; ++i) {
            if (s[i] == t[i]) continue;
            int moves = (s[i] < t[i] ? 0 : 26) + t[i] - s[i];
            /*while (used.count(moves) && moves <= k)
                moves += 26;
            printf("%c -> %c: %d \n", s[i], t[i], moves);
            if (moves <= k) used.insert(moves);
            else return false;*/
            if (used[moves] != 0) used[moves] += 26;
            else used[moves] = moves;
            // printf("%c -> %c: %d \n", s[i], t[i], used[moves]);
            if (used[moves] > k) return false;
        }
        return true;
    }
};