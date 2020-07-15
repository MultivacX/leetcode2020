// 1514. Path with Maximum Probability
// https://leetcode.com/problems/path-with-maximum-probability/

// Runtime: 432 ms, faster than 12.50% of C++ online submissions for Path with Maximum Probability.
// Memory Usage: 80.2 MB, less than 100.00% of C++ online submissions for Path with Maximum Probability.

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, unordered_map<int, double>> _edges;
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0];
            int b = edges[i][1];
            _edges[a][b] = succProb[i];
            _edges[b][a] = succProb[i];
        }
        
        vector<double> probabilities(n, 0);
        probabilities[start] = 1;
        vector<int> q{start};
        while (!q.empty()) {
            vector<int> next_q;
            for (int a : q) {
                for (auto it : _edges[a]) {
                    int b = it.first;
                    double p = it.second * probabilities[a];
                    if (p <= probabilities[b]) continue;
                    probabilities[b] = p;
                    next_q.push_back(b);
                }
            }
            q = next_q;
        }
        return probabilities[end];
    }
};

// Time Limit Exceeded
// 10 / 16 test cases passed.
/*class Solution {
    unordered_map<int, unordered_map<int, double>> _edges;
    
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0];
            int b = edges[i][1];
            _edges[a][b] = succProb[i];
            _edges[b][a] = succProb[i];
        }
        
        vector<double> probabilities(n, 0);
        probabilities[start] = 1;
        dfs(start, end, 1, probabilities);
        return probabilities[end];
    }
    
    void dfs(int start, int end, double probability, vector<double>& probabilities) {
        if (start == end) return;
        
        for (const auto& it : _edges[start]) {
            int b = it.first;
            double p = it.second * probability;
            if (p <= probabilities[b]) continue;
            probabilities[b] = p;
            dfs(b, end, p, probabilities);
        }
    }
};*/