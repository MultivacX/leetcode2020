// 332. Reconstruct Itinerary
// https://leetcode.com/problems/reconstruct-itinerary/

// Runtime: 44 ms, faster than 74.31% of C++ online submissions for Reconstruct Itinerary.
// Memory Usage: 13.6 MB, less than 98.53% of C++ online submissions for Reconstruct Itinerary.

class Solution {
    unordered_map<string, vector<int>> g;
    vector<string> path;
    int airports;
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        airports = tickets.size() + 1;
        for (int i = 0; i < tickets.size(); ++i)
            g[tickets[i][0]].push_back(i);
        for (auto& it : g) 
            sort(begin(it.second), end(it.second), [&](int a, int b){ return tickets[a][1] < tickets[b][1]; });
        vector<bool> visited(tickets.size(), false);
        find(tickets, visited, "JFK");
        return path;
    }
    
    bool find(const vector<vector<string>>& tickets, vector<bool>& visited, const string& start) {
        path.push_back(start);
        if (path.size() == airports) return true;
        int pre_idx = -1;
        for (int idx : g[start]) {
            if (visited[idx]) continue;
            if (pre_idx != -1 && tickets[pre_idx][1] == tickets[idx][1]) continue;
            visited[idx] = true;
            if (find(tickets, visited, tickets[idx][1])) return true;
            visited[idx] = false;
        }
        path.pop_back();
        return false;
    }
};