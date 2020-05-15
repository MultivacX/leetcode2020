// 859. Buddy Strings

// Runtime: 12 ms, faster than 23.17% of C++ online submissions for Buddy Strings.
// Memory Usage: 6.9 MB, less than 100.00% of C++ online submissions for Buddy Strings.

// Time Complexity: O(A.length()).
// Space Complexity: O(1).

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) return false;
        vector<int> cnt(26, 0);
        bool swaped = false;
        int j = -1;
        for (int i = 0; i < A.length(); ++i) {
            ++cnt[A[i] - 'a'];
            if (A[i] == B[i]) continue;
            
            if (j < 0) {
                j = i;
            } else if (swaped || A[j] != B[i] || A[i] != B[j]) {
                return false;
            } else {
                swaped = true;;
            }
        }
        if (!swaped) {
            for (int i : cnt) if (i > 1) return true;
        }
        return swaped;
    }
};