class Solution {
public:
    bool checkStrings(string s1, string s2) {
        const int n = s1.length();
        int a[26] = {0};

        for (int i = 0; i < n; i += 2) {
            ++a[s1[i] - 'a'];
            --a[s2[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (a[i]) return false;
        }

        for (int i = 1; i < n; i += 2) {
            ++a[s1[i] - 'a'];
            --a[s2[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (a[i]) return false;
        }

        return true;
    }
};