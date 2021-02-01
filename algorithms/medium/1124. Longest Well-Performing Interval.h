// 1124. Longest Well-Performing Interval
// https://leetcode.com/problems/longest-well-performing-interval/

// Runtime: 60 ms, faster than 81.70% of C++ online submissions for Longest Well-Performing Interval.
// Memory Usage: 23.4 MB, less than 5.93% of C++ online submissions for Longest Well-Performing Interval.

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        const int N = hours.size();
        int ans = 0;
        // {non-positive count, index}
        unordered_map<int, int> m{{0, -1}};
        for (int i = 0, cnt = 0; i < N; ++i) {
            if (hours[i] > 8) ++cnt;
            else --cnt;
            if (cnt > 0) ans = max(ans, i + 1);
            else {
                if (m.count(cnt - 1)) ans = max(ans, i - m[cnt - 1]);
                if (m.count(cnt) == 0) m.emplace(cnt, i);
            }
        }
        return ans;
    }
};