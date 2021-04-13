// 1824. Minimum Sideway Jumps
// https://leetcode.com/problems/minimum-sideway-jumps/

// Runtime: 228 ms, faster than 91.79% of C++ online submissions for Minimum Sideway Jumps.
// Memory Usage: 187.9 MB, less than 62.95% of C++ online submissions for Minimum Sideway Jumps.
    
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        const int M = INT_MAX / 2;
        const int N = obstacles.size();
        array<int, 3> jumps{1, 0, 1};
        for (int i = 1; i < N - 1; ++i) {
            int pre = obstacles[i - 1];
            int cur = obstacles[i]; 
            if (pre == cur) continue;
            
            int j = pre - 1, k = cur - 1;
            
            if (pre == 0) {
                jumps[k] = M;
                continue;  
            }
            
            if (0 == cur) {
                jumps[j] = min(jumps[(j + 1) % 3], jumps[(j + 2) % 3]) + 1;
                continue;  
            }
            
            int x = 3 - j - k;
            jumps[j] = min(jumps[k] + 1, jumps[x]) + 1;
            jumps[k] = M;
        }
        return min(jumps[0], min(jumps[1], jumps[2]));
    }
};