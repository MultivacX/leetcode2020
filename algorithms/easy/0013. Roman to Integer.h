// 13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer/

// Runtime: 4 ms, faster than 92.80% of C++ online submissions for Roman to Integer.
// Memory Usage: 6.5 MB, less than 55.26% of C++ online submissions for Roman to Integer.
    
class Solution {
public:
    int romanToInt(string s) {
        static unordered_map<char, int> m{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
            {'C', 100}, {'D', 500}, {'M', 1000}, 
        };
        
        const int N = s.length();
        int ans = 0, i = 0;
        while (i < N) {
                 if (s[i] == 'I' && i + 1 < N && s[i + 1] == 'V') ans += 4,   i += 2;
            else if (s[i] == 'I' && i + 1 < N && s[i + 1] == 'X') ans += 9,   i += 2;
            else if (s[i] == 'X' && i + 1 < N && s[i + 1] == 'L') ans += 40,  i += 2;
            else if (s[i] == 'X' && i + 1 < N && s[i + 1] == 'C') ans += 90,  i += 2;
            else if (s[i] == 'C' && i + 1 < N && s[i + 1] == 'D') ans += 400, i += 2;
            else if (s[i] == 'C' && i + 1 < N && s[i + 1] == 'M') ans += 900, i += 2;
            else ans += m[s[i++]];
        }
        return ans;
    }
};