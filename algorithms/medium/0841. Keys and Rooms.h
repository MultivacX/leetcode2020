// 841. Keys and Rooms

// Runtime: 20 ms, faster than 46.46% of C++ online submissions for Keys and Rooms.
// Memory Usage: 10.8 MB, less than 80.00% of C++ online submissions for Keys and Rooms.

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int N = rooms.size();
        vector<int> visited(N, 0);
        visited[0] = 1;
        unordered_set<int> keys(begin(rooms[0]), end(rooms[0]));
        while (!keys.empty()) {
            unordered_set<int> tmp;
            for (int key : keys) {
                if (visited[key]) continue;
                visited[key] = 1;
                for (int next : rooms[key]) {
                    if (visited[next]) continue;
                    tmp.insert(next);
                }
            }
            keys = tmp;
        }
        return accumulate(begin(visited), end(visited), 0) == N;
    }
};