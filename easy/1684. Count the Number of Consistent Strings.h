// 1684. Count the Number of Consistent Strings
// https://leetcode.com/problems/count-the-number-of-consistent-strings/

// Runtime: 92 ms, faster than 77.33% of C++ online submissions for Count the Number of Consistent Strings.
// Memory Usage: 30.4 MB, less than 77.59% of C++ online submissions for Count the Number of Consistent Strings.
    
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> v(26, false);
        for (char c : allowed) v[c - 'a'] = true;
        int ans = 0;
        for (const auto& w : words) {
            int b = 1;
            for (char c : w) if (!v[c - 'a']) { b = 0; break; }
            ans += b;
        }
        return ans;
    }
};