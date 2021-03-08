// 753. Cracking the Safe
// https://leetcode.com/problems/cracking-the-safe/

// Runtime: 8 ms, faster than 87.94% of C++ online submissions for Cracking the Safe.
// Memory Usage: 7.9 MB, less than 86.53% of C++ online submissions for Cracking the Safe.

class Solution {
public:
    string crackSafe(int n, int k) {
        int N = pow(k, n);
        unordered_set<string> pwds;
        
        string ans(n, '0');
        while (--N > 0) {
            string cur(ans.substr(ans.length() - (n - 1), n - 1));
            for (int i = k - 1; i >= 0; --i) {
                cur.push_back('0' + i);
                if (pwds.insert(cur).second) {
                    ans.push_back('0' + i);
                    break;
                }
                cur.pop_back();
            }
        }
        return ans;
    }
};