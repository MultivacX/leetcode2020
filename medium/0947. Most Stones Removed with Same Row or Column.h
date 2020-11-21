// 947. Most Stones Removed with Same Row or Column
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {        
        const int M = 10000;
        const int N = stones.size();
        
        unordered_map<int, unordered_set<int>> x2y, y2x;
        unordered_map<int, unordered_map<int, int>> xy2i;
        for (int i = 0; i < N; ++i) {
            int x = stones[i][0];
            int y = stones[i][1];
            x2y[x].insert(y);
            y2x[y].insert(x);
            xy2i[x][y] = i;
        }
        
        vector<int> uf(N, -1);
        for (int i = 0; i < N; ++i) {
            int k = uf[i] >= 0 ? uf[i] : i;
            int x = stones[i][0];
            int y = stones[i][1];

            for (int y : x2y[x]) if (uf[xy2i[x][y]] >= 0 && uf[xy2i[x][y]] < k) k = uf[xy2i[x][y]];
            for (int x : y2x[y]) if (uf[xy2i[x][y]] >= 0 && uf[xy2i[x][y]] < k) k = uf[xy2i[x][y]];

            for (int y : x2y[x]) uf[xy2i[x][y]] = k;
            for (int x : y2x[y]) uf[xy2i[x][y]] = k;

            uf[i] = k;
        }
        
        vector<int> n(N, 0);
        for (int i = 0; i < N; ++i) ++n[uf[i]];
        
        // for (int i = 0; i < N; ++i) 
        //     printf("%d:(%d,%d) -> %d:(%d,%d)\n", 
        //            i, stones[i][0], stones[i][1], 
        //            uf[i], stones[uf[i]][0], stones[uf[i]][1]);
        // cout << endl;
        // for (int i = 0; i < N; ++i) cout << n[i] << ", "; cout << endl;
        
        int ans = 0;
        for (int i = 0; i < N; ++i) if (n[i] > 1) ans += n[i] - 1;
        return ans;
    }
};

// TLE
/*class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {        
        const int N = stones.size();
        vector<int> uf(N, -1);
        for (int i = 0; i < N; ++i) {
            if (uf[i] >= 0) continue;
            
            uf[i] = i;
            
            unordered_set<int> idx;
            for (int j = i + 1; j < N; ++j) {
                if (uf[j] >= 0) continue;
                idx.insert(j);
            }
            
            unordered_set<int> x_pos{stones[i][0]}, y_pos{stones[i][1]};
            while (!idx.empty()) {
                int size = idx.size();
                for (int j : idx) {
                    int x = stones[j][0];
                    int y = stones[j][1];
                    if (x_pos.count(x) || y_pos.count(y)) {
                        x_pos.insert(x);
                        y_pos.insert(y);
                        uf[j] = i;
                        idx.erase(j);
                        break;
                    }
                }
                if (size == idx.size()) break;
            }
        }
        
        vector<int> n(N, 0);
        for (int i = 0; i < N; ++i) ++n[uf[i]];
        
        // for (int i = 0; i < N; ++i) 
        //     printf("%d:(%d,%d) -> %d:(%d,%d)\n", 
        //            i, stones[i][0], stones[i][1], 
        //            uf[i], stones[uf[i]][0], stones[uf[i]][1]);
        // cout << endl;
        // for (int i = 0; i < N; ++i) cout << n[i] << ", "; cout << endl;
        
        int ans = 0;
        for (int i = 0; i < N; ++i) if (n[i] > 1) ans += n[i] - 1;
        return ans;
    }
};*/