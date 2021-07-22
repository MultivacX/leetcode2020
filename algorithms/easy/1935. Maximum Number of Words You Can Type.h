// 1935. Maximum Number of Words You Can Type
// https://leetcode.com/problems/maximum-number-of-words-you-can-type/

// Runtime: 4 ms, faster than 70.27% of C++ online submissions for Maximum Number of Words You Can Type.
// Memory Usage: 6.6 MB, less than 89.29% of C++ online submissions for Maximum Number of Words You Can Type.
    
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int b = (1 << 26) - 1;
        for (char c : brokenLetters) {
            int a = 1 << (c - 'a');
            b -= a;
        }
        // cout << bitset<26>(b) << endl;
        
        const int n = text.length();
        int k = 0, i = 0;
        bool broken = false;
        while (i < n) {
            if (text[i] != ' ') {
                int a = 1 << (text[i] - 'a');
                // cout << bitset<26>(a) << endl;
                if (!broken) broken = (b & a) == 0;
            }
                 
            if (text[i] == ' ' || i + 1 == n) {
                if (!broken) ++k;
                broken = false;
            }
            ++i;
            
        }
        return k;
    }
};