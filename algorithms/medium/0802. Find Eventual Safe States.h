// 802. Find Eventual Safe States
// https://leetcode.com/problems/find-eventual-safe-states/

// Runtime: 540 ms, faster than 14.76% of C++ online submissions for Find Eventual Safe States.
// Memory Usage: 356.8 MB, less than 5.00% of C++ online submissions for Find Eventual Safe States.

class Solution {
    int visit(vector<vector<int>>& graph, vector<int>& states, vector<int>& visited, int i) {
        visited[i] = true;
        
        states[i] = 1;
        for (int j : graph[i]) {
            if (!visited[j]) {
                if (states[j] == 0) states[i] = max(states[i], visit(graph, states, visited, j));
                else states[i] = max(states[i], states[j]);
            } else {
                states[i] = 2;
            }
        }
        
        visited[i] = false;
        return states[i];
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int N = graph.size();
        vector<int> ans;
        // 0 : not visit
        // 1 : safe
        // 2 : unsafe
        vector<int> states(N, 0);
        for (int i = 0; i < N; ++i) {
            if (states[i] == 0) {
                vector<int> visited(N, 0);
                visit(graph, states, visited, i);
            }
            if (states[i] == 1)
                ans.push_back(i);
            // cout << i << ": "; for (int s : states) cout << s << " "; cout << endl;
        }
        return ans;
    }
};

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