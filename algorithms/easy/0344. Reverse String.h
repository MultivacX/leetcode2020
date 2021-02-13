// 344. Reverse String
// https://leetcode.com/problems/reverse-string/

// Runtime: 32 ms, faster than 79.54% of C++ online submissions for Reverse String.
// Memory Usage: 23.5 MB, less than 37.15% of C++ online submissions for Reverse String.

class Solution {
public:
    void reverseString(vector<char>& s) {
        const int N = s.size();
        int i = 0; 
        int j = N - 1;
        while (i < j) swap(s[i++], s[j--]);
    }
};

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = (int)s.size() - 1;
        while (i < j) swap(s[i++], s[j--]);
    }
};