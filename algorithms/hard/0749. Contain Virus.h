// 749. Contain Virus
// https://leetcode.com/problems/contain-virus/

// Runtime: 60 ms, faster than 26.32% of C++ online submissions for Contain Virus.
// Memory Usage: 33.7 MB, less than 23.68% of C++ online submissions for Contain Virus.
    
class Solution {
    struct Region {
        Region() {}
        unordered_set<int> infected{};
        unordered_set<int> boundary{};
        int walls{0};
    };
    
    int m;
    int n;
    int step;
    
    void dfs(vector<vector<int>>& isInfected, int i, int j, Region& r) {
        if (i < 0 || i >= m) return;
        if (j < 0 || j >= n) return;
        
        if (isInfected[i][j] == 0) {
            r.boundary.emplace(i * n + j);
            r.walls += 1;
        } else if (isInfected[i][j] == step) {
            isInfected[i][j] = step + 1;
            r.infected.emplace(i * n + j);
            dfs(isInfected, i - 1, j, r);
            dfs(isInfected, i + 1, j, r);
            dfs(isInfected, i, j - 1, r);
            dfs(isInfected, i, j + 1, r);
        }
    }
    
public:
    int containVirus(vector<vector<int>>& isInfected) {
        m = isInfected.size();
        n = isInfected[0].size();
        step = 0;
        
        int walls = 0;
        while (true) {
            ++step;
            vector<Region> regions;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (isInfected[i][j] != step)
                        continue;
                    Region r;
                    dfs(isInfected, i, j, r);
                    regions.emplace_back(r);
                }
            }
            if (regions.empty()) break;
            
            // build walls
            int k = max_element(begin(regions), end(regions), [](const Region& l, const Region& r){ return l.boundary.size() < r.boundary.size();  }) - begin(regions);
            swap(regions[k], regions.back());
            for (int k : regions.back().infected)
                isInfected[k / n][k % n] = -1;
            walls += regions.back().walls;
            regions.pop_back();
            
            // infect
            for (auto& r : regions) 
                for (int k : r.boundary)
                    isInfected[k / n][k % n] = step + 1;
        }
        return walls;
    }
};