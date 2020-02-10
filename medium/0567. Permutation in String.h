// 567. Permutation in String

// Runtime: 12 ms, faster than 73.79% of C++ online submissions for Permutation in String.
// Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions for Permutation in String.

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        if (m > n)
            return false;
        
        int cnt1[26] = {0};
        int cnt2[26] = {0};
        for (const char& c : s1)
            ++cnt1[c - 'a'];
        
        int start = -1;
        for (int i = 0; i < n; ++i) {
            int idx = s2[i] - 'a';
            if (cnt1[idx] == 0) {
                memset(cnt2, 0, 26 * sizeof(int));
                start = -1;
                continue;
            }
            
            if (start < 0)
                start = i;
            ++cnt2[idx];
            while (cnt2[idx] > cnt1[idx] && start < i)
                --cnt2[s2[start++] - 'a'];
            
            if (i - start + 1 == m)
                return true;
        }
        return false;
    }
};