// 763. Partition Labels

// Runtime: 16 ms, faster than 16.55% of C++ online submissions for Partition Labels.
// Memory Usage: 7.2 MB, less than 100.00% of C++ online submissions for Partition Labels.

// Time Complexity: O(N + I * lg(I)). I = [1, 26]
// Space Complexity: O(I).

class Solution {
public:
    vector<int> partitionLabels(string S) {
        const int N = S.length();
        // {char, [start, end)}
        unordered_map<char, pair<int, int>> m;
        for (int i = 0; i < N; ++i) {
            if (m.count(S[i]) == 0) m[S[i]] = {i, i + 1};
            else m[S[i]].second = i + 1;
        }
        vector<pair<int, int>> intervals;
        for (auto& it : m) intervals.emplace_back(it.second);
        sort(begin(intervals), end(intervals));
        vector<int> ans;
        int i = 0;
        int s = intervals[i].first;
        int e = intervals[i].second;
        while (i < intervals.size()) {
            if (i + 1 == intervals.size()) {
                ans.emplace_back(e - s);
                break;
            }
            ++i;
            int next_s = intervals[i].first;
            int next_e = intervals[i].second;
            if (e <= next_s) {
                ans.emplace_back(e - s);
                s = next_s;
                e = next_e;
            } else {
                e = max(e, next_e);
            }
        }
        return ans;
    }
};