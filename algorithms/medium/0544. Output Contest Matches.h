// 544. Output Contest Matches
// https://leetcode.com/problems/output-contest-matches/

// Runtime: 8 ms, faster than 52.63% of C++ online submissions for Output Contest Matches.
// Memory Usage: 9 MB, less than 98.95% of C++ online submissions for Output Contest Matches.
    
class Solution {
public:
    string findContestMatch(int n) {
        vector<string> matches(n / 2);
        for (int i = 0; i < n / 2; ++i)
            matches[i] = "(" + to_string(i + 1) + "," + to_string(n - i) + ")";
        n /= 2;
        while (n > 1) {
            for (int i = 0; i < n / 2; ++i) 
                matches[i] = "(" + matches[i] + "," + matches[n - i - 1] + ")";
            n /= 2;
        }
        return matches[0];
    }
};