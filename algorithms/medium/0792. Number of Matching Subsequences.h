// 792. Number of Matching Subsequences

// Runtime: 392 ms, faster than 48.11% of C++ online submissions for Number of Matching Subsequences.
// Memory Usage: 44.3 MB, less than 33.33% of C++ online submissions for Number of Matching Subsequences.

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int ans = 0;
        vector<vector<int>> cnt(26);
        for (int i = 0; i < S.length(); ++i) cnt[S[i] - 'a'].push_back(i);
        for (const auto& word : words) {
            int i = 0;
            for (int j = -1; i < word.length(); ++i) {
                const vector<int>& W = cnt[word[i] - 'a'];
                auto it = upper_bound(begin(W), end(W), j);
                if (it == end(W)) break;
                j = *it;
            }
            if (i == word.length()) ++ans;
        }
        return ans;
    }
};