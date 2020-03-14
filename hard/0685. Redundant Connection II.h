// 685. Redundant Connection II

// Runtime: 16 ms, faster than 23.24% of C++ online submissions for Redundant Connection II.
// Memory Usage: 11.8 MB, less than 20.00% of C++ online submissions for Redundant Connection II.

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        const int N = edges.size();
        
        vector<unordered_set<int>> outdegrees(N + 1, unordered_set<int>()); // i -> {...}
        vector<unordered_set<int>> indegrees(N + 1, unordered_set<int>()); // i <- {...}
        for (auto& edge : edges) {
            outdegrees[edge[0]].insert(edge[1]);
            indegrees[edge[1]].insert(edge[0]);
        }
        // find root
        int root = 0;
        for (int i = 1; i <= N; ++i) {
            if (indegrees[i].size() == 0) {
                root = i;
                break;   
            }
        }
        // remove leaf node which has 1 parent
        deque<int> leaves;
        for (int i = 1; i <= N; ++i) {
            if (outdegrees[i].size() == 0 && indegrees[i].size() == 1) 
                leaves.push_back(i);
        }
        while (!leaves.empty()) {
            int size = leaves.size();
            while (size--) {
                int leaf = leaves.front();
                leaves.pop_front();
                
                int parent = *indegrees[leaf].begin();
                outdegrees[parent].erase(leaf);
                indegrees[leaf].erase(parent);
                if (outdegrees[parent].size() == 0 && indegrees[parent].size() == 1) 
                    leaves.push_back(parent);
            }
        }
        // cout << "root: " << root << endl << endl;
        // output(outdegrees, indegrees, N);
            
        int c = 0;
        if (root != 0) {
            // not a cycle
            //   1
            //  / \
            // v   v
            // 2-->3
            for (int i = 1; i <= N; ++i) {
                if (indegrees[i].size() != 2) 
                    continue;
                
                c = i;
                
                if (outdegrees[i].size() != 0) 
                    break;
                
                for (int j = N - 1; j >= 0; --j) {
                    if (edges[j][1] == i) 
                        return edges[j];
                }
            }
            
            // cycle
            // 5 -> 1 -> 2
            //      ^    |
            //      |    v
            //      4 <- 3
            // cout << "c0: " << c << endl << endl;
        }
        
        if (c == 0) {
            // cycle
            // 1 -> 2
            // ^    |
            // |    v
            // 4 <- 3
            for (int i = 1; i <= N; ++i) {
                if (outdegrees[i].size() == 1 && indegrees[i].size() == 1) {
                    c = i;
                    break;
                }
            }
            // cout << "c1: " << c << endl << endl;
        }
        
        unordered_set<int> cycle_edges;
        deque<int> cycle_nodes;
        cycle_nodes.push_back(c);
        while (!cycle_nodes.empty()) {
            int size = cycle_nodes.size();
            while (size--) {
                int u = cycle_nodes.front();
                cycle_nodes.pop_front();
                
                int v = *outdegrees[u].begin();
                cycle_edges.insert(u * (N + 7) + v);
                // cout << "cycle: " << u << " -> " << v << endl;
                if (v == c) {
                    cycle_nodes.clear();
                    break;
                }
                cycle_nodes.push_back(v);
            }
        }
        for (int j = N - 1; j >= 0; --j) {
            if (cycle_edges.count(edges[j][0] * (N + 7) + edges[j][1])) {
                if ((root != 0 && edges[j][1] == c) || root == 0)
                    return edges[j];
            }
        }
        
        return {};
    }
    
//     void output(vector<unordered_set<int>>& outdegrees, vector<unordered_set<int>>& indegrees, int N) {
//         for (int i = 1; i <= N; ++i) {
//             for (int j : indegrees[i]) {
//                 printf("%d <- %d, ", i, j);
//             }
//             cout << endl;
//         }
//         for (int i = 1; i <= N; ++i) {
//             for (int j : outdegrees[i]) {
//                 printf("%d -> %d, ", i, j);
//             }
//             cout << endl;
//         }
//         cout << endl;
//     }
};