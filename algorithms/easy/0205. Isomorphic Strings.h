// 205. Isomorphic Strings

// Runtime: 20 ms, faster than 44.25% of C++ online submissions for Isomorphic Strings.
// Memory Usage: 7.1 MB, less than 100.00% of C++ online submissions for Isomorphic Strings.

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        const int N = s.length();
        for (int i = 0; i < N; ++i) {
            int cnt = s2t.count(s[i]) + t2s.count(t[i]);
            if (cnt == 1) return false;
            else if (cnt == 0) s2t[s[i]] = t[i], t2s[t[i]] = s[i];
            else if (s2t[s[i]] != t[i] || t2s[t[i]] != s[i]) return false;
        }
        return true;
    }
};


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const int n = s.length();
        vector<int> s2t(256, -1);
        vector<int> t2s(256, -1);
        for (int i = 0; i < n; ++i) {
            int j = s[i], k = t[i];
            if (s2t[j] == -1 && t2s[k] == -1) {
                s2t[j] = k;
                t2s[k] = j;
            } else if (s2t[j] != k || t2s[k] != j) {
                return false;
            }
        }
        return true;
    }
};