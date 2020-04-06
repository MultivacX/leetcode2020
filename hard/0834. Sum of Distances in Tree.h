// 834. Sum of Distances in Tree

// Runtime: 220 ms, faster than 10.62% of C++ online submissions for Sum of Distances in Tree.
// Memory Usage: 36.2 MB, less than 33.33% of C++ online submissions for Sum of Distances in Tree.

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        if (edges.empty()) return {0};

        unordered_map<int, unordered_set<int>> graph;
        for (auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        
        vector<int> children_count(N, 0);
        { vector<bool> visited(N, false); count_children(graph, visited, 0, children_count);}
        // for (int i = 0; i < N; ++i) cout << i << ":" << children_count[i] << endl;
        
        vector<int> ans(N, 0);
        { vector<bool> visited(N, false); ans[0] = distances(graph, visited); }
        get_distances(N, graph, children_count, ans);
            
        // vector<int> levels(N, -1);
        // get_levels(graph, levels);
        // ans[0] = accumulate(begin(levels), end(levels), 0);
        // for (int i = 0; i < N; ++i) cout << string(levels[i] + 1, ' ') << i << ":" << levels[i] << endl;
        
        // i --> j
        // ans[i] + (N - children_count[j] - 2) = ans[j] + children_count[j]
        // ans[j] = ans[i] + (N - children_count[j] * 2 - 2)
        
        return ans;
    }
    
    void get_distances(int N, unordered_map<int, unordered_set<int>>& graph, vector<int>& children_count, vector<int>& ans) {
        deque<int> q;
        q.push_back(0);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i = q.front();
                q.pop_front();
                for (int j : graph[i]) {
                    if (ans[j]) continue;
                    ans[j] = ans[i] + (N - children_count[j] * 2 - 2);
                    q.push_back(j);
                }
            }
        }
    }
    
    int distances(unordered_map<int, unordered_set<int>>& graph, vector<bool>& visited) {
        int distance = 0;
        deque<int> q;
        q.push_back(0);
        int lv = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i = q.front();
                q.pop_front();
                if (visited[i]) continue;
                visited[i] = true;
                distance += lv;
                for (int j : graph[i]) {
                    if (visited[j]) continue;
                    q.push_back(j);
                }
            }
            ++lv;
        }
        return distance;
    }
    
    int count_children(unordered_map<int, unordered_set<int>>& graph, vector<bool>& visited, int i, vector<int>& children_count) {
        if (visited[i]) return 0;
        visited[i] = true;
        for (int j : graph[i]) {
            if (visited[j]) continue;
            children_count[i] += 1 + count_children(graph, visited, j, children_count);
        }
        return children_count[i];
    }
    
    // void get_levels(unordered_map<int, unordered_set<int>>& graph, vector<int>& levels) {
    //     deque<int> q;
    //     q.push_back(0);
    //     int lv = 0;
    //     while (!q.empty()) {
    //         int size = q.size();
    //         while (size--) {
    //             int i = q.front();
    //             q.pop_front();
    //             if (levels[i] >= 0) continue;
    //             levels[i] = lv;
    //             for (int j : graph[i]) {
    //                 if (levels[j] >= 0) continue;
    //                 q.push_back(j);
    //             }
    //         }
    //         ++lv;
    //     }
    // }
};

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