// 800. Similar RGB Color
// https://leetcode.com/problems/similar-rgb-color/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Similar RGB Color.
// Memory Usage: 6.6 MB, less than 28.89% of C++ online submissions for Similar RGB Color.
    
class Solution {
    char find(char a, char b) {
        static unordered_map<char, int> m{
            {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, 
            {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, 
            {'a', 10}, {'b', 11}, {'c', 12},
            {'d', 13}, {'e', 14}, {'f', 15},
        };
        static unordered_map<char, int> n{
            {0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'}, 
            {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'}, 
            {10, 'a'}, {11, 'b'}, {12, 'c'},
            {13, 'd'}, {14, 'e'}, {15, 'f'},
        };
        int z = m[a] * 16 + m[b];
        int v = z / 17;
        int ans = v;
        int d = INT_MAX;
        for (int i = v - 1; i <= v + 1; ++i) {
            if (0 <= i && i <= 15 && abs(17 * i - z) < d) {
                ans = i;
                d = abs(17 * i - z);
            }
        }
        return n[ans];
    }
    
public:
    string similarRGB(string color) {
        string colour = "#";
        char r = find(color[1], color[2]);
        colour += r; colour += r;
        char g = find(color[3], color[4]);
        colour += g; colour += g;
        char b = find(color[5], color[6]);
        colour += b; colour += b;
        return colour;
    }
};