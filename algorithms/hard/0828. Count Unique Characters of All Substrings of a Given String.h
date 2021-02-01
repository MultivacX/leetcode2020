// 828. Count Unique Characters of All Substrings of a Given String
// https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/

// Runtime: 12 ms, faster than 66.99% of C++ online submissions for Count Unique Characters of All Substrings of a Given String.
// Memory Usage: 10.4 MB, less than 14.12% of C++ online submissions for Count Unique Characters of All Substrings of a Given String.

class Solution {
public:
    int uniqueLetterString(string s) {
        const int N = s.length();
        vector<vector<int>> n(26, vector<int>{-1});
        for (int i = 0; i < N; ++i) 
            n[s[i] - 'A'].push_back(i);
        for (int i = 0; i < 26; ++i) 
            n[i].push_back(N);
        int64_t ans = 0;
        for (int i = 0; i < 26; ++i) {
            auto& v = n[i];
            const int L = v.size();
            for (int j = 1; j <= L - 2; ++j) 
                ans = (ans + (int64_t)(v[j] - v[j - 1]) * int64_t(v[j + 1] - v[j])) % 1000000007;
        }
        return ans;
    }
};

// TLE
/*class Solution {
public:
    int uniqueLetterString(string s) {
        const int N = s.length();
        int64_t ans = N;
        vector<int> l(N, 0); // removed
        vector<int> m(N, 0); // mask
        vector<int> n(N, 1); // count
        for (int i = 0; i < N; ++i) 
            m[i] = 1 << (s[i] - 'A');
        
        for (int j = 1; j < N; ++j) {
            l.pop_back();
            m.pop_back();
            n.pop_back();
            for (int i = 0; i + j < N; ++i) {
                int k = 1 << (s[i + j] - 'A');
                if (m[i] & k) { if ((l[i] & k) == 0) { --n[i]; l[i] |= k; } }
                else ++n[i];
                if (n[i] < 0) n[i] = 0;
                ans = (ans + n[i]) % 1000000007;
                m[i] |= k;
                
                // cout << s.substr(i, j + 1) << ":" << n[i] << ", ";
            }
            // cout << endl;
        }
        return ans;
    }
};*/