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

// Runtime: 24 ms
// Memory Usage: 17.6 MB
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int i : asteroids) {
            if (ans.empty() || ans.back() < 0 || i > 0) 
                ans.push_back(i);
            else {
                int j = (int)ans.size() - 1;
                while (j >= 0) {
                    if (ans[j] + i == 0) {
                        ans.pop_back();
                        break;
                    }
                    
                    if (ans[j] + i > 0) break;
                    
                    if (ans[j] < 0) {
                        ans.push_back(i);
                        break;
                    }
                    
                    ans.pop_back();
                    --j;
                }
                if (j < 0) ans.push_back(i);
            }
        }
        return ans;
    }
};