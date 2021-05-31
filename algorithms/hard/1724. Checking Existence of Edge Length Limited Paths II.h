// 1724. Checking Existence of Edge Length Limited Paths II
// https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths-ii/

// Runtime: 808 ms, faster than 18.03% of C++ online submissions for Checking Existence of Edge Length Limited Paths II.
// Memory Usage: 202.9 MB, less than 27.87% of C++ online submissions for Checking Existence of Edge Length Limited Paths II.
    
class DistanceLimitedPathsExist {
    struct UF {
        int p{-1};
        int w{1};
    };
    
    const int _n;
    vector<vector<pair<int, int>>> _g;
    vector<UF> _uf;
    
    int find(int u) {
        if (_uf[u].p != u)
            return find(_uf[u].p);
        return u;
    }
    
public:
    DistanceLimitedPathsExist(int n, vector<vector<int>>& edgeList) 
    : _n(n)
    , _g(n)
    , _uf(n) {
        for (int i = 0; i < n; ++i)
            _uf[i].p = i;
        
        for (const auto& e : edgeList) {
            int u = e[0], v = e[1];
            _g[u].push_back({v, e[2]});
            _g[v].push_back({u, e[2]});
            
            int up = find(u), vp = find(v);
            if (up == vp) continue;
            if (_uf[up].w >= _uf[vp].w) {
                _uf[up].w += _uf[vp].w;
                _uf[vp].p = _uf[up].p;
            } else {
                _uf[vp].w += _uf[up].w;
                _uf[up].p = _uf[vp].p;
            }
        }
    }
    
    bool query(int p, int q, int limit) {
        if (find(p) != find(q)) return false;
        
        vector<bool> b(_n);
        b[p] = true;
        queue<int> nodes;
        nodes.push(p);
        while (!nodes.empty() && !b[q]) {
            int size = nodes.size();
            while (size-- > 0 && !b[q]) {
                int u = nodes.front();
                nodes.pop();
                for (const auto& [v, w] : _g[u])
                    if (!b[v] && w < limit)
                        b[v] = true,
                        nodes.push(v);
            }
        }
        return b[q];
    }
};

/**
 * Your DistanceLimitedPathsExist object will be instantiated and called as such:
 * DistanceLimitedPathsExist* obj = new DistanceLimitedPathsExist(n, edgeList);
 * bool param_1 = obj->query(p,q,limit);
 */