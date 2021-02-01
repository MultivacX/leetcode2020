// 345. Reverse Vowels of a String
// https://leetcode.com/problems/reverse-vowels-of-a-string/

// Runtime: 16 ms, faster than 67.14% of C++ online submissions for Reverse Vowels of a String.
// Memory Usage: 8.2 MB, less than 12.82% of C++ online submissions for Reverse Vowels of a String.

class Solution {
public:
    string reverseVowels(string s) {
        static const unordered_set<char> vowels{
            'a', 'e', 'i', 'o', 'u', 
            'A', 'E', 'I', 'O', 'U'
        };
        int i = 0;
        int j = (int)s.length() - 1;
        while (i < j) {
            if (vowels.count(s[i]) == 0) ++i;
            else if (vowels.count(s[j]) == 0) --j;
            else swap(s[i++], s[j--]);
        }
        return s;
    }
};