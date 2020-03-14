// 834. Sum of Distances in Tree

// Time Limit Exceeded
// 64 / 69 test cases passed.
/*class Solution {
public:
    // (nodes_i)---i---j---(nodes_j)
    // sum(i) = dists(i, nodes_i) + count(nodes_j) + dists(j, nodes_j)
    // sum(j) = dists(j, nodes_j) + count(nodes_i) + dists(i, nodes_i)

    // sum(i) + count(nodes_i) = sum(j) + count(nodes_j)
    // count(nodes_i) + count(nodes_j) + 2 = E
    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        const int E = N - 1 == edges.size() ? N : edges.size();

        unordered_map<int, unordered_set<int>> m;
        for (auto& edge : edges) {
            m[edge[0]].insert(edge[1]);
            m[edge[1]].insert(edge[0]);
        }
        
        vector<int> sums(N, -1);
        int i = 0;
        sums[i] = distances(0, m);
        deque<int> q;
        q.push_back(i);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int u = q.front();
                q.pop_front();
                for (int v : m[u]) {
                    if (sums[v] != -1) continue;    
                    sums[v] = sums[u] + count(u, v, m) * 2 + 2 - E;
                    q.push_back(v);
                }
            }
        }
        return sums;
    }
    
    int distances(int i, unordered_map<int, unordered_set<int>>& m) {
        int sum = 0;
        unordered_set<int> visited{i};
        int level = 0;
        deque<int> q;
        q.push_back(i);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int u = q.front();
                q.pop_front();
                sum += level;
                for (int v : m[u]) {
                    if (visited.count(v)) continue;    
                    visited.insert(v);
                    q.push_back(v);
                }
            }
            ++level;
        }
        return sum;
    }

    int count(int i, int j, unordered_map<int, unordered_set<int>>& m) {
        unordered_set<int> visited{i, j};
        deque<int> q;
        q.push_back(i);
        while (!q.empty()) {
            int size = q.size();
            int u = q.front();
            q.pop_front();
            for (int v : m[u]) {
                if (visited.count(v)) continue;    
                visited.insert(v);
                q.push_back(v);
            }
        }
        return visited.size() - 2;
    }
};*/