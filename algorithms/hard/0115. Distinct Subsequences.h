// 115. Distinct Subsequences

// Runtime: 4 ms, faster than 99.34% of C++ online submissions for Distinct Subsequences.
// Memory Usage: 6.7 MB, less than 100.00% of C++ online submissions for Distinct Subsequences.

// S = "babgbag", T = "bag"

// b        a        g
// 0->1|5
//          1->3|6
// 2->5
//
// 4->5              3
//          5->6
//                   6

// b        a        g
// dp[0&2&4]
//          dp[1&5]=3
// dp[2&4]
//
// dp[4]              dp[3&6]=2
//          dp[5]=1
//                    dp[6]=1

class Solution {
public:
    int numDistinct(string s, string t) {
        const int M = s.length();
        const int N = t.length();
        if (M <= N) return s == t ? 1 : 0;
        
        unordered_map<char, vector<int>> m;
        unordered_set<char> n(begin(t), end(t));
        for (int i = 0; i < M; ++i) if (n.count(s[i])) m[s[i]].emplace_back(i);
        
        // for (const auto& c : t) {
        //     cout << c << ": ";
        //     for (int i : m[c]) cout << i << " ";
        //     cout << endl;
        // }
        // cout << endl;
        
        vector<vector<uint64_t>> dp(N, vector<uint64_t>());
        
        int i = N - 1;
        const auto& cur_idx = m[t[i]];
        auto& cur_cnt = dp[i];
        const int size = cur_idx.size();
        cur_cnt.resize(size);
        for (int j = 0; j < size; ++j) cur_cnt[j] = size - j;
        
        for (i = N - 2; i >= 0; --i) {
            const auto& next_idx = m[t[i + 1]];
            const auto& next_cnt = dp[i + 1];
            
            // cout << t[i] << ": " << endl;
            
            const auto& cur_idx = m[t[i]];
            auto& cur_cnt = dp[i];
            const int size = cur_idx.size();
            cur_cnt.resize(size);
            for (int j = size - 1; j >= 0; --j) {
                // cout << "    " << cur_idx[j] << " ";
                auto it = upper_bound(begin(next_idx), end(next_idx), cur_idx[j]);
                if (it == end(next_idx)) {
                    cur_cnt[j] = 0;
                } else {
                    int k = it - begin(next_idx);
                    // cout << next_idx[k] << endl;
                    cur_cnt[j] = next_cnt[k] + (j + 1 < size ? cur_cnt[j + 1] : 0);
                }
            }
        }
        
        // cout << endl;
        // for (int i = 0; i < N; ++i) {
        //     cout << t[i] << ": ";
        //     for (int j : dp[i]) cout << j << " ";
        //     cout << endl;
        // }
        
        return dp[0][0];
    }
};