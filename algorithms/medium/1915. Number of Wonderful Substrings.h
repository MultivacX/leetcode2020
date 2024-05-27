// https://leetcode.com/problems/number-of-wonderful-substrings/
// 1915. Number of Wonderful Substrings

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;
        vector<long long> m(1024);
        m[0] = 1;
        int mask = 0;
        for (char c : word) {
            mask ^= (1 << (c - 'a'));
            ans += m[mask];
            for (int i = 0; i < 10; ++i) {
                int tmp = mask ^ (1 << i);
                ans += m[tmp];
            }
            ++m[mask];
        }
        return ans;
    }
};