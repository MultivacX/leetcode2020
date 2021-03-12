// 387. First Unique Character in a String

// Runtime: 40 ms, faster than 79.67% of C++ online submissions for First Unique Character in a String.
// Memory Usage: 12.9 MB, less than 68.75% of C++ online submissions for First Unique Character in a String.

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> cnt(26, 0);
        for (char c : s) 
            ++cnt[c - 'a'];
        
        for (int i = 0; i < s.length(); ++i) 
            if (cnt[s[i] - 'a'] == 1)
                return i;
        return -1;
     }
};


class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> idx(26, -1);
        for (int i = 0; i < s.length(); ++i) {
            int j = s[i] - 'a';
            if (idx[j] == -1) idx[j] = i;
            else idx[j] = -2;
        }
        int ans = -1;
        for (int i = 0; i < 26; ++i) {
            if (idx[i] >= 0 && (ans == -1 || ans > idx[i])) {
                ans = idx[i];
            }
        }
        return ans;
    }
};