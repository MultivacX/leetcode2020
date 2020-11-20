// 828. Count Unique Characters of All Substrings of a Given String
// https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/

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