// 1625. Lexicographically Smallest String After Applying Operations
// https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/

// Runtime: 4 ms, faster than 99.58% of C++ online submissions for Lexicographically Smallest String After Applying Operations.
// Memory Usage: 7.2 MB, less than 95.05% of C++ online submissions for Lexicographically Smallest String After Applying Operations.

class Solution {
    vector<int> getAOps(int a) {
        // (i + aOps[i] * a) % 10 -> min
        vector<int> aOps(10, 0);
        for (int i = 0; i < 10; ++i) {
            vector<int> cnt(10, -1); cnt[i] = 0;
            int k = 1; int v = (i + k * a) % 10;
            while (v != i) {
                cnt[v] = k++;
                v = (i + k * a) % 10;
            }
            for (int j = 0; j < 10; ++j) {
                if (cnt[j] < 0) continue;
                aOps[i] = cnt[j]; break;
            }
            // cout << '(' << i << '+' << aOps[i] * a << ")%10=" << (i + aOps[i] * a) % 10 << endl;
        }
        return aOps;
    }
    
public:
    string findLexSmallestString(string s, int a, int b) {
        const int N = s.length();
        vector<int> aOps(getAOps(a));
        // cout << s << endl;
        string ans(s);
        int i = 0;
        do {
            for (int i = 1, k = aOps[s[1] - '0']; i < N; i += 2) {
                s[i] = (s[i] - '0' + k * a) % 10 + '0';
            }
            if (b & 1) 
                for (int i = 0, k = aOps[s[0] - '0']; i < N; i += 2) {
                    s[i] = (s[i] - '0' + k * a) % 10 + '0';
                }
            if (s < ans) ans = s;
            // cout << s << endl;
            s = s.substr(N - b) + s.substr(0, N - b);
            i = (i + b) % N;
        } while (i);
        
        return ans;
    }
};