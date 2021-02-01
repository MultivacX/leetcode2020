// 1047. Remove All Adjacent Duplicates In String
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

// Runtime: 20 ms, faster than 73.83% of C++ online submissions for Remove All Adjacent Duplicates In String.
// Memory Usage: 10.5 MB, less than 70.57% of C++ online submissions for Remove All Adjacent Duplicates In String.
    
class Solution {
public:
    string removeDuplicates(string S) {
        string t;
        for (char c : S) {
            if (t.empty() || t.back() != c) t.push_back(c);
            else t.pop_back();
        }
        return t;
    }
};