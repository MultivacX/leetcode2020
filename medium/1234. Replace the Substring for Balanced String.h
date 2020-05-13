// 1234. Replace the Substring for Balanced String

// Runtime: 128 ms, faster than 24.69% of C++ online submissions for Replace the Substring for Balanced String.
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Replace the Substring for Balanced String.

// Time Complexity: O(L).
// Space Complexity: O(1).

class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> cnt;
        for (const char& c : s) ++cnt[c];
        if (cnt['Q'] == cnt['W'] && cnt['W'] == cnt['E'] && cnt['E'] == cnt['R']) 
            return 0;
        
        const int L = s.length();
        const int N = s.length() >> 2;
        int l = 0;
        int r = 0;
        int ans = L;
        while (r < L) {
            --cnt[s[r]];
            // check outside_of_window[0, l)&(r,L)
            // while window[l,r] replaced for balance, move left-bound 1 step to right
            while (l <= r && cnt['Q'] <= N && cnt['W'] <= N && cnt['E'] <= N && cnt['R'] <= N) {
                ans = min(ans, r - l + 1);
                ++cnt[s[l++]];
            }
            ++r;
        }
        return ans;
    }
}; 