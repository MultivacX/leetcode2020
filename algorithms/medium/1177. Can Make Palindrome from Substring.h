// 1177. Can Make Palindrome from Substring

// Runtime: 620 ms, faster than 37.06% of C++ online submissions for Can Make Palindrome from Substring.
// Memory Usage: 93.4 MB, less than 100.00% of C++ online submissions for Can Make Palindrome from Substring.

// Time Complexity: O(S + Q).
// Space Complexity: O(S + Q).

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        const int S = s.length();
        // from s[0] to s[i]
        // pre_masks[i]'s bit[j] 0/1 means even/odd of count(j + 'a')
        vector<int> pre_masks(S, 0);
        for (int i = 0; i < S; ++i) {
            pre_masks[i] = (1 << (s[i] - 'a')) ^ (i == 0 ? 0 : pre_masks[i - 1]);
            // cout << bitset<26>(pre_masks[i]) << endl;
        }
        
        const int Q = queries.size();
        vector<bool> ans(Q, false);
        for (int i = 0; i < Q; ++i) {
            int l = queries[i][0] == 0 ? 0 : pre_masks[queries[i][0] - 1];
            int r = pre_masks[queries[i][1]];
            bitset<26> mask = l ^ r;
            // cout << mask << " " << mask.count() << endl;
            ans[i] = mask.count() >> 1 <= queries[i][2];
        }
        return ans;
    }
};