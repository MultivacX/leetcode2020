// 727. Minimum Window Subsequence
// https://leetcode.com/problems/minimum-window-subsequence/

// Runtime: 84 ms, faster than 65.14% of C++ online submissions for Minimum Window Subsequence.
// Memory Usage: 11.7 MB, less than 58.97% of C++ online submissions for Minimum Window Subsequence.
    
class Solution {
public:
    string minWindow(string S, string T) {
        const int M = S.length();
        const int N = T.length();
        
        vector<vector<int>> counter(26);
        for (char c : T) 
            if (counter[c - 'a'].empty())
                counter[c - 'a'].push_back(-1);
        for (int i = 0; i < M; ++i)
            if (!counter[S[i] - 'a'].empty())
                counter[S[i] - 'a'].push_back(i);
        
        int idx = -1;
        int len = INT_MAX;
        for (int i = 0; i < M; ++i) {
            if (S[i] != T[0]) continue;
            
            int k = i;
            for (int j = 1; j < N; ++j) {
                const auto& v = counter[T[j] - 'a'];
                auto it = upper_bound(begin(v), end(v), k);
                if (it == end(v)) {
                    k = -1;
                    break;
                }
                k = *it;
            }
            if (k != -1 && len > k - i + 1) {
                idx = i;
                len = k - i + 1;
            }
        }
        
        return idx != -1 ? S.substr(idx, len) : "";
    }
};