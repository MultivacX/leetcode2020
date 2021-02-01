// 709. To Lower Case
// https://leetcode.com/problems/to-lower-case/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for To Lower Case.
// Memory Usage: 6.3 MB, less than 84.40% of C++ online submissions for To Lower Case.
    
class Solution {
public:
    string toLowerCase(string str) {
        for (char& c : str)
            if ('A' <= c && c <= 'Z')
                c = c - 'A' + 'a';
        return str;
    }
};