// 1871. Jump Game VII
// https://leetcode.com/problems/jump-game-vii/

// Runtime: 56 ms, faster than 12.50% of C++ online submissions for Jump Game VII.
// Memory Usage: 22.7 MB, less than 12.50% of C++ online submissions for Jump Game VII.
    
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.back() == '1') return false;
        
        const int n = s.length();
        s[0] = '#';
        vector<int> v(n + 1); // prefix count of #
        v[1] = 1;
        for (int i = 1; i < n; ++i) {
            v[i + 1] = v[i];
            if (s[i] == '1') continue;
            
            int r = i - minJump;
            if (r + 1 < 0) continue;

            int l = max(0, i - maxJump);

            if (v[r + 1] > v[l]) {
                s[i] = '#';
                ++v[i + 1];    
            }
        }
        return s.back() == '#';
    }
};