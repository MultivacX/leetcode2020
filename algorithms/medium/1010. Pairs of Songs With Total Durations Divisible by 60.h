// 1010. Pairs of Songs With Total Durations Divisible by 60
// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

// Runtime: 80 ms, faster than 28.20% of C++ online submissions for Pairs of Songs With Total Durations Divisible by 60.
// Memory Usage: 23.7 MB, less than 44.65% of C++ online submissions for Pairs of Songs With Total Durations Divisible by 60.

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> m;
        int ans = 0;
        for (int t : time) {
            int r = t % 60;
            int x = r == 0 ? r : (60 - r);
            // cout << t << ": " << r << " " << x << endl;
            ans += (m.count(x) ? m[x] : 0);
            ++m[r];
        }
        return ans;
    }
};