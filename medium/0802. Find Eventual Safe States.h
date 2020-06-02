// 802. Find Eventual Safe States
// https://leetcode.com/problems/find-eventual-safe-states/

// Time Limit Exceeded
// 82 / 111 test cases passed.
class Solution {
    unordered_set<int> unsafe;
    unordered_set<int> visited;
    
    void find_loop(vector<vector<int>>& graph, int i) {
        if (visited.count(i)) {
            unsafe.insert(begin(visited), end(visited));
            return;
        }
        
        visited.insert(i);
        for (int j : graph[i]) find_loop(graph, j);
        visited.erase(i);
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int N = graph.size();
        for (int i = 0; i < N; ++i) {
            if (unsafe.count(i)) continue;
            visited.clear();
            find_loop(graph, i);
        }
        
        vector<int> ans;
        for (int i = 0; i < N; ++i) {
            if (unsafe.count(i)) continue;
            ans.push_back(i);
        }
        return ans;
    }
};