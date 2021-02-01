// 899. Orderly Queue

// Runtime: 4 ms, faster than 91.82% of C++ online submissions for Orderly Queue.
// Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Orderly Queue.

class Solution {
public:
    string orderlyQueue(string S, int K) {
        const int N = S.length();
        if (N <= 1) return S;
        
        if (K > 1) {
            sort(begin(S), end(S));
            return S;
        }
        
        string min_s(S);
        char min_c = S[0];
        for (const char& c : S) min_c = min(min_c, c);
        for (int i = 0; i < N; ++i) {
            if (S[i] != min_c) continue;
            string tmp(S.substr(i));
            if (i > 0) tmp += S.substr(0, i);
            if (tmp < min_s) min_s = tmp;
        }
        return min_s;
    }
};