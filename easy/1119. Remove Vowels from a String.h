// 1119. Remove Vowels from a String
// https://leetcode.com/problems/remove-vowels-from-a-string/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Vowels from a String.
// Memory Usage: 6.3 MB, less than 99.84% of C++ online submissions for Remove Vowels from a String.
    
class Solution {
public:
    string removeVowels(string s) {
        static const string v = "aeiou";
        string t;
        for (char c : s)
            if (v.find(c) == string::npos)
                t += c;
        return t;
    }
};