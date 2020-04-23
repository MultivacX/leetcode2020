// 735. Asteroid Collision

// Runtime: 20 ms, faster than 41.46% of C++ online submissions for Asteroid Collision.
// Memory Usage: 7.4 MB, less than 100.00% of C++ online submissions for Asteroid Collision.

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int a : asteroids) {
            while (!ans.empty() && ans.back() > 0 && a < 0) {
                if (ans.back() + a == 0) ans.pop_back(), a = 0;
                else if (ans.back() + a < 0) ans.pop_back();
                else a = 0;
            }
            if (a != 0) ans.push_back(a);
        }
        return ans;
    }
};