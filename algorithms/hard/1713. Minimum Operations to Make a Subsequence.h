// 1713. Minimum Operations to Make a Subsequence
// https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/

// Runtime: 316 ms, faster than 97.50% of C++ online submissions for Minimum Operations to Make a Subsequence.
// Memory Usage: 109.9 MB, less than 95.57% of C++ online submissions for Minimum Operations to Make a Subsequence.
    
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        const int N = target.size();
        unordered_map<int, int> m;
        for (int i = 0; i < N; ++i)
            m.emplace(target[i], i);
        
        vector<int> v;
        for (int a : arr) {
            if (m.count(a) == 0) continue;
            auto it = lower_bound(begin(v), end(v), m[a]);
            if (it == end(v)) {
                v.emplace_back(m[a]);
            } else if (*it != m[a]) {
                *it = m[a];
            }
        }
        return N - v.size();
    }
};