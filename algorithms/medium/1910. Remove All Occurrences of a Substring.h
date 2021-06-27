// 1910. Remove All Occurrences of a Substring
// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

// Runtime: 12 ms, faster than 100.00% of C++ online submissions for Remove All Occurrences of a Substring.
// Memory Usage: 9.1 MB, less than 20.00% of C++ online submissions for Remove All Occurrences of a Substring.
    
class Solution {
public:
    string removeOccurrences(string s, string part) {
        // cout << s << endl;
        auto i = s.find(part);
        if (i == string::npos) return s;
        return removeOccurrences(s.substr(0, i) + s.substr(i + part.length()), part);
    }
};