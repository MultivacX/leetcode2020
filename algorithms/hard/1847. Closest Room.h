// 1847. Closest Room
// https://leetcode.com/problems/closest-room/

// Runtime: 1032 ms, faster than 21.23% of C++ online submissions for Closest Room.
// Memory Usage: 168.6 MB, less than 23.12% of C++ online submissions for Closest Room.

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        for (int i = 0; i < queries.size(); ++i)
            queries[i].push_back(i);
        
        auto f = [](const vector<int>& l, const vector<int>& r){
            return l[1] < r[1];
        };
        sort(begin(rooms), end(rooms), f);
        sort(begin(queries), end(queries), f);
        
        vector<int> ans(queries.size(), -1);
        set<int> ids;
        int i = queries.size() - 1, j = rooms.size() - 1;
        while (i >= 0) {
            int preferred = queries[i][0];
            int minSize = queries[i][1];
            int k = queries[i--][2];
            
            while (j >= 0 && rooms[j][1] >= minSize) 
                ids.insert(rooms[j--][0]);
            
            if (ids.empty()) continue;
            
            // auto it = lower_bound(begin(ids), end(ids), preferred); // TLE
            auto it = ids.lower_bound(preferred);
            if (it == end(ids)) { 
                --it; 
                ans[k] = *it; 
            } else if (it == begin(ids)) {
                ans[k] = *it;
            } else { 
                int r = *it; 
                int l = *(--it);
                ans[k] = abs(preferred - l) <= abs(preferred - r) ? l : r;
            }
        }
        return ans;
    }
};