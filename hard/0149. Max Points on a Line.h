// 149. Max Points on a Line

// Runtime: 112 ms, faster than 5.01% of C++ online submissions for Max Points on a Line.
// Memory Usage: 35.3 MB, less than 7.14% of C++ online submissions for Max Points on a Line.

class Solution {
public:
    using K = vector<int>;
    using P = set<K>;
    
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        
        map<K, int> c;
        for (auto& p : points) ++c[p];
        
        map<K, map<K, P>> m;
        for (auto i = c.begin(); i != c.end(); ++i) {
            for (auto j = c.begin(); j != c.end(); ++j) {
                if (i == j) continue;
                auto k = f(i->first[0], i->first[1], j->first[0], j->first[1]);
                if (k[0] == 0 && k[1] == 0) continue;
                m[i->first][k].insert(j->first);
                m[j->first][k].insert(i->first);
            }
        }
        
        int ans = 0;
        for (auto it : c) ans = max(ans, it.second);
        for (auto& kkp : m) {
            for (auto it : kkp.second) {
                int cnt = c[kkp.first];
                //cout << cnt << " -- " << kkp.first[0] << ", " << kkp.first[1] << " : " << it.first[0] << " / " << it.first[1] << endl;
                for (auto p : it.second) {
                    cnt += c[p];
                    //cout << "    " << p[0] << ", " << p[1] << " = " << c[p] << endl;
                }
                ans = max(ans, cnt);
            }
            cout << endl;
        }
        return ans;
    }
    
    // k = (y2 - y1 ) / (x2, x1)
    K f(int x1, int y1, int x2, int y2) {
        int64_t y = y2 - y1;
        int64_t x = x2 - x1;
        
        if (y == 0 && x == 0) return {0, 0};
        if (y == 0 && x > 0) return {0, 1};
        if (y == 0 && x < 0) return {0, 1};
        if (y > 0 && x == 0) return {1, 0};
        if (y < 0 && x == 0) return {1, 0};
        
        int i = ((y > 0 && x > 0) || (y < 0 && x < 0)) ? 1 : -1;
        y = abs(y);
        x = abs(x);
        auto g = gcd(y, x);
        return {y / g, i * x / g};
    }
};