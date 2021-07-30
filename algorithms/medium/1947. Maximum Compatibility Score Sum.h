// 1947. Maximum Compatibility Score Sum
// https://leetcode.com/problems/maximum-compatibility-score-sum/

// Runtime: 240 ms, faster than 44.25% of C++ online submissions for Maximum Compatibility Score Sum.
// Memory Usage: 9.9 MB, less than 78.39% of C++ online submissions for Maximum Compatibility Score Sum.
    
class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        const int m = mentors.size();
        const int n = mentors[0].size();
        sort(mentors.begin(), mentors.end());
        int ans = 0;
        do {
            int sum = 0;
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                    sum += 1 - (students[i][j] ^ mentors[i][j]);
            ans = max(ans, sum);
        } while (next_permutation(mentors.begin(), mentors.end()));
        return ans;
    }
};