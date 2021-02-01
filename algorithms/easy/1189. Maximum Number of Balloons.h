// 1189. Maximum Number of Balloons
// https://leetcode.com/problems/maximum-number-of-balloons/

// Runtime: 8 ms, faster than 36.61% of C++ online submissions for Maximum Number of Balloons.
// Memory Usage: 7.1 MB, less than 31.45% of C++ online submissions for Maximum Number of Balloons.

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // b1 a1 l2 o2 n1
        const unordered_set<char> balloon{'b', 'a', 'l', 'o', 'n'};
        unordered_map<char, int> m;
        for (char c : text) 
            if (balloon.count(c))
                ++m[c];
        int c1 = min(m['b'], min(m['a'], m['n']));
        int c2 = min(m['l'], m['o']);
        return min(c1, c2 / 2);
    }
};