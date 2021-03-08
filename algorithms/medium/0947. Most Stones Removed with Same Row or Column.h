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


class Solution {
    struct subset {
        int parent;
        int rank;
    };
    
    // A utility function to find set of an element i
    // (uses path compression technique)
    int find(vector<subset>& s, int i) {
        // find root and make root as parent of i (path
        // compression)
        if (s[i].parent != i)
            s[i].parent = find(s, s[i].parent);

        return s[i].parent;
    }

    // A function that does union of two sets of x and y
    // (uses union by rank)
    void Union(vector<subset>& s, int xroot, int yroot) {
        if (xroot == yroot) return;
        
        // Attach smaller rank tree under root of high rank tree
        // (Union by Rank)
        if (s[xroot].rank < s[yroot].rank)
            s[xroot].parent = yroot;
        else if (s[xroot].rank > s[yroot].rank)
            s[yroot].parent = xroot;

        // If ranks are same, then make one as root and
        // increment its rank by one
        else {
            s[yroot].parent = xroot;
            s[xroot].rank++;
        }
    }
    
public:
    int removeStones(vector<vector<int>>& stones) {
        const int n = stones.size();
        vector<subset> s(n);
        for (int i = 0; i < n; ++i) 
            s[i].parent = i;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (stones[i][0] != stones[j][0] && stones[i][1] != stones[j][1])
                    continue;
                Union(s, find(s, i), find(s, j));
            }
        }
        
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) ++m[find(s, i)];
        
        int ans = 0;
        for (const auto& it : m) ans += it.second - 1;
        return ans;
    }
};