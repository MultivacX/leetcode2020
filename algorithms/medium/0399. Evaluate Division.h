// 399. Evaluate Division

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Evaluate Division.
// Memory Usage: 6.7 MB, less than 100.00% of C++ online submissions for Evaluate Division.

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i) 
            update(equations[i][0], equations[i][1], values[i]);
        
        vector<double> ans;
        for (const auto& q : queries) {
            unordered_set<string> visited;
            double v = cal(q[0], q[1], visited);
            ans.push_back(v);
            update(q[0], q[1], v);
        }
        return ans;
    }
    
    unordered_map<string, unordered_map<string, double>> forest;
    
    void update(const string& a, const string& b, double v) {
        if (v >= 0) {
            forest[a][b] = v;
            if (v != 0) {
                forest[b][a] = 1.0 / v;
                forest[a][a] = 1.0;
                forest[b][b] = 1.0;
            }
        }
    }
    
    double cal(const string& a, const string& b, unordered_set<string>& visited) {
        if (forest.count(a) == 0 || forest.count(b) == 0) return -1.0;
        
        visited.insert(a);
        for (auto it : forest[a]) {
            const string& c = it.first;
            if (c == b) return it.second;
            if (visited.count(c)) continue;
            double v = cal(c, b, visited);
            if (v >= 0) return it.second * v;
        }
        visited.erase(a);
        
        return -1.0;
    }
};