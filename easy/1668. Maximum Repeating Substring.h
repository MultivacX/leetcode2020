// 1668. Maximum Repeating Substring
// https://leetcode.com/problems/maximum-repeating-substring/

// Runtime: 4 ms, faster than 39.44% of C++ online submissions for Maximum Repeating Substring.
// Memory Usage: 6.5 MB, less than 77.77% of C++ online submissions for Maximum Repeating Substring.

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans = 0;
        string w(word);
        while (sequence.find(w) != string::npos) {
            ++ans;
            w += word;
        }
        return ans;
    }
};