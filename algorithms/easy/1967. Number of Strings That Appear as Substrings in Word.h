// 1967. Number of Strings That Appear as Substrings in Word
// https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/

// Runtime: 4 ms, faster than 92.48% of C++ online submissions for Number of Strings That Appear as Substrings in Word.
// Memory Usage: 8.7 MB, less than 70.44% of C++ online submissions for Number of Strings That Appear as Substrings in Word.
    
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int k = 0;
        for (const auto& p : patterns)
            if (word.find(p) != string::npos)
                ++k;
        return k;
    }
};