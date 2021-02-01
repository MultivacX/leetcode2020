// 886. Possible Bipartition

// Runtime: 272 ms, faster than 14.00% of C++ online submissions for Possible Bipartition.
// Memory Usage: 74.6 MB, less than 14.29% of C++ online submissions for Possible Bipartition.

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        unordered_map<int, unordered_set<int>> m;
        for (const auto& v : dislikes) {
            m[v[0]].insert(v[1]);
            m[v[1]].insert(v[0]);
        }
        
        unordered_set<int> g1;
        unordered_set<int> g2;
        for (int i = 1; i <= N; ++i) {
            if (g1.count(i) || g2.count(i)) continue;
            
            if (!f(m, i, g1, g2, true))
                return false;
        }
        return true;
    }
    
    bool f(unordered_map<int, unordered_set<int>>& m, int i, unordered_set<int>& g1, unordered_set<int>& g2, bool isG1) {
        if (isG1) {
            if (g2.count(i)) return false;
            if (g1.count(i)) return true;
            g1.insert(i);
        } else {
            if (g1.count(i)) return false;
            if (g2.count(i)) return true;
            g2.insert(i);
        }
        
        for (int j : m[i]) 
            if (!f(m, j, g1, g2, !isG1)) 
                return false;
        
        return true;
    }
};