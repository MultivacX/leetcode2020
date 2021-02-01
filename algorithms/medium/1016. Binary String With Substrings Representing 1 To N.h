// 1016. Binary String With Substrings Representing 1 To N
// https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary String With Substrings Representing 1 To N.
// Memory Usage: 6.9 MB, less than 31.51% of C++ online submissions for Binary String With Substrings Representing 1 To N.
    
class Solution {
public:
    bool queryString(string S, int N) {
        // bits : [0, 30]
        // substrings start with 1
        const int L = S.length();
        // vector<int> visited(N + 1, 0);
        unordered_set<int> s;
        for (int i = 0; i < L; ++i) {
            if (S[i] == '0') continue;
            
            for (int j = 0, v = 0; j < 31 && i + j < L; ++j) {
                v = S[i + j] - '0' + (v << 1);
                // cout << S[i + j] << ':' << v << ' ';
                if (v > N) break;
                // visited[v] = 1;
                s.insert(v);
            }
            // cout << endl;
        }
        // for (int i = 1; i <= N; ++i) cout << i << ':' << visited[i] << ' '; cout << endl;
        // return accumulate(begin(visited), end(visited), 0) == N;
        return s.size() == N;
    }
};