// 679. 24 Game
// https://leetcode.com/problems/24-game/

// Runtime: 24 ms, faster than 57.51% of C++ online submissions for 24 Game.
// Memory Usage: 10.1 MB, less than 49.35% of C++ online submissions for 24 Game.

class Solution {
    bool judge(double A, double B) {
        cout << A + B << ", " << A - B << ", " << A * B << ", " << A + B << ", " << (B == 0 ? 0 : A / B) << endl;
        if (abs(A + B - 24) < 1e-6) return true;
        if (abs(A - B - 24) < 1e-6) return true;
        if (abs(A * B - 24) < 1e-6) return true;
        if (B != 0 && abs(A / B - 24) < 1e-6) return true;
        return false;
    }
    
public:
    bool judgePoint24(vector<int>& nums) {
        // (a b) OPT (c d)
        // {i, {j, {nums[i] OPT nums[j]}}}
        unordered_map<int, unordered_map<int, unordered_set<double>>> opt2;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (i == j) continue;
                opt2[i][j].insert(nums[i] + nums[j]);
                opt2[i][j].insert(nums[i] - nums[j]);
                opt2[i][j].insert((double)nums[i] * nums[j]);
                opt2[i][j].insert((double)nums[i] / nums[j]);
            }
        }
        
        unordered_set<int> idxs{0, 1, 2, 3};
        for (int i = 0; i < 4; ++i) {
            idxs.erase(i);
            for (int j = 0; j < 4; ++j) {
                if (i == j) continue;
                idxs.erase(j);
                
                auto it = idxs.begin();
                int x = *it;
                int y = *(++it);
                
                for (auto ab : opt2[i][j]) {
                    for (auto cd : opt2[x][y]) {
                        if (judge(ab, cd)) return true;
                    }
                    
                    for (auto cd : opt2[y][x]) {
                        if (judge(ab, cd)) return true;
                    }
                }
                
                idxs.insert(j);    
            }
            idxs.insert(i);
        }
        
        // (a) OPT (b c d)
        // (a b c) OPT (d)
        // {i, {j, {k, {nums[i] OPT nums[j] OPT nums[k]}}}}
        unordered_map<int, unordered_map<int, unordered_map<int, unordered_set<double>>>> opt3;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (i == j) continue;
                for (int k = 0; k < 4; ++k) {
                    if (i == k || j == k) continue;
                    for (auto ab : opt2[i][j]) {
                        opt3[i][j][k].insert(ab + nums[k]);
                        opt3[i][j][k].insert(ab - nums[k]);
                        opt3[i][j][k].insert(ab * nums[k]);
                        opt3[i][j][k].insert(ab / nums[k]);
                    }
                    for (auto bc : opt2[j][k]) {
                        opt3[i][j][k].insert(nums[i] + bc);
                        opt3[i][j][k].insert(nums[i] - bc);
                        opt3[i][j][k].insert(nums[i] * bc);
                        if (bc != 0) opt3[i][j][k].insert(nums[i] / bc);
                    }
                }
            }
        }
        
        for (int i = 0; i < 4; ++i) {
            idxs.erase(i);
            for (int j = 0; j < 4; ++j) {
                if (i == j) continue;
                idxs.erase(j);
                for (int k = 0; k < 4; ++k) {
                    if (i == k || j == k) continue;
                    idxs.erase(k);
                    
                    int x = *idxs.begin();
                    
                    for (auto abc : opt3[i][j][k]) {
                        if (judge(abc, nums[x])) return true;
                        if (judge(nums[x], abc)) return true;
                    }
                    
                    idxs.insert(k);
                }
                idxs.insert(j);    
            }
            idxs.insert(i);
        }
        
        return false;
    }
};