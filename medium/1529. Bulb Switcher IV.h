// 1529. Bulb Switcher IV
// https://leetcode.com/problems/bulb-switcher-iv/

// Runtime: 20 ms, faster than 94.96% of C++ online submissions for Bulb Switcher IV.
// Memory Usage: 9.6 MB, less than 31.61% of C++ online submissions for Bulb Switcher IV.

class Solution {
public:
    int minFlips(string target) {
        const int N = target.length();
        
        int left = 0;
        while (left < N && target[left] == '0') ++left;
        
        int right = N - 1;
        while (right >= 0 && target[right] == '1') --right;
        
        // cout << target << endl;
        // for (int i = 0; i < N; ++i) cout << (i < left || i > right ? '*' : target[i]); cout << endl;
        
        int ans = right < N - 1 ? 1 : 0;
        for (int i = right; i >= left; --i) {
            if (i + 1 < N && target[i] != target[i + 1]) {
                ++ans;
            }
        }
        if (ans & 1) {
            ans += target[N - 1] == '0' ? 1 : 0;
        } else {
            ans += target[N - 1] == '0' ? 0 : 1;
        }
        return ans;
    }
};