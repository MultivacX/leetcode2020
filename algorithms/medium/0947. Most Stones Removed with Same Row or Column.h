// 947. Most Stones Removed with Same Row or Column
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

// Runtime: 52 ms, faster than 96.64% of C++ online submissions for Most Stones Removed with Same Row or Column.
// Memory Usage: 21.8 MB, less than 34.01% of C++ online submissions for Most Stones Removed with Same Row or Column.

class Solution {
    int find(vector<int>& parents, int i) {
        if (parents[i] == i) return i;
        return find(parents, parents[i]);
    }
    
    void uni(vector<int>& parents, int i, int j) {
        parents[find(parents, i)] = parents[find(parents, j)];
    }
    
public:
    int removeStones(vector<vector<int>>& stones) {
        if (stones.size() <= 1) return 0;
        
        vector<int> parents(20000);
        for (int i = 0; i < 20000; ++i)
            parents[i] = i;
        for (const auto& s : stones)
            uni(parents, s[0], s[1] + 10000);
        
        // for (const auto& s : stones) 
        //     printf("(%d,%d) px[%d]=%d py[%d+1W]=%d\n", s[0], s[1], s[0], parents[s[0]], s[1], parents[s[1]+10000]);
        // for (const auto& s : stones) 
        //     printf("find(%d)=%d find(%d+1W)=%d\n", s[0], find(parents, s[0]), s[1], find(parents, s[1]+10000));
        
        unordered_map<int, int> m;
        for (const auto& s : stones) ++m[find(parents, s[0])];
        
        int ans = 0;
        for (auto it : m) ans += it.second - 1;
        return ans;
    }
};