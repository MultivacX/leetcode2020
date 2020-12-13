// 1100. Find K-Length Substrings With No Repeated Characters
// https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/

// Runtime: 4 ms, faster than 85.17% of C++ online submissions for Find K-Length Substrings With No Repeated Characters.
// Memory Usage: 6.8 MB, less than 91.80% of C++ online submissions for Find K-Length Substrings With No Repeated Characters.
    
class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        const int N = S.length();
        if (K > N || K > 26) return 0;
        int ans = 0;
        vector<int> weights(26, 0);
        for (int i = 0, k = 0; i < N; ++i) {
            int j = S[i] - 'a';
            if (i + 1 > K) {
                int l = S[i - K] - 'a';
                int w = weights[l] == 1 ? 1 : 100;
                weights[l] -= w;
                k -= w;
            }
            int w = weights[j] == 0 ? 1 : 100;
            weights[j] += w;
            k += w;
            if (k == K) ++ans;
        }
        return ans;
    }
};