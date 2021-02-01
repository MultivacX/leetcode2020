// 87. Scramble String

// Runtime: 8 ms, faster than 83.38% of C++ online submissions for Scramble String.
// Memory Usage: 12.6 MB, less than 71.43% of C++ online submissions for Scramble String.

class Solution {
public:
    bool isScramble(string s1, string s2) {
        // cout << s1 << " -- " << s2 << endl;
        
        const int N = s1.length();
        if (N <= 1) return s1 == s2;
        if (N <= 3) {
            sort(begin(s1), end(s1));
            sort(begin(s2), end(s2));
            return s1 == s2;
        }
        
        vector<int> l1(26, 0);
        vector<int> l2(26, 0);
        for (int i = 0; i < N - 1; ++i) {
            ++l1[s1[i] - 'a'];
            ++l2[s2[i] - 'a'];
            if (l1 != l2) continue;
            if (isScramble(s1.substr(0, i + 1), s2.substr(0, i + 1)) && isScramble(s1.substr(i + 1), s2.substr(i + 1))) return true;
        }
        
        vector<int> r1(26, 0);
        vector<int> r2(26, 0);
        for (int i = 0, j = N - 1; i < N - 1; ++i, --j) {
            ++r1[s1[i] - 'a'];
            ++r2[s2[j] - 'a'];
            if (r1 != r2) continue;
            if (isScramble(s1.substr(0, i + 1), s2.substr(j)) && isScramble(s1.substr(i + 1), s2.substr(0, j))) return true;
        }
        
        return false;
    }
};