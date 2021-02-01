// 657. Robot Return to Origin
// https://leetcode.com/problems/robot-return-to-origin/

// Runtime: 12 ms, faster than 75.84% of C++ online submissions for Robot Return to Origin.
// Memory Usage: 8.2 MB, less than 93.04% of C++ online submissions for Robot Return to Origin.
    
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char c : moves) {
            if (c == 'L') --x;
            else if (c == 'R') ++x;
            else if (c == 'D') --y;
            else ++y;
        }
        return x == 0 && y == 0;
    }
};

// Runtime: 48 ms, faster than 6.66% of C++ online submissions for Robot Return to Origin.
// Memory Usage: 8.6 MB, less than 5.68% of C++ online submissions for Robot Return to Origin.
    
class Solution {
public:
    bool judgeCircle(string moves) {
        static unordered_map<char, array<int, 2>> m{
            {'L', {-1, 0}}, {'R', {1, 0}},
            {'D', {0, -1}}, {'U', {0, 1}},
        };
        int x = 0, y = 0;
        for (char c : moves) x += m[c][0], y += m[c][1];
        return x == 0 && y == 0;
    }
};