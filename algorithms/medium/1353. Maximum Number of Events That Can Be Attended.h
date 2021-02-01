// 1353. Maximum Number of Events That Can Be Attended

// Runtime: 1532 ms, faster than 5.11% of C++ online submissions for Maximum Number of Events That Can Be Attended.
// Memory Usage: 128.2 MB, less than 100.00% of C++ online submissions for Maximum Number of Events That Can Be Attended.

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int ans = 0;
        
        // {can_start_day, {end_day, cnt}}
        map<int, map<int, int>> m;
        for (const auto& e : events) ++m[e[0]][e[1]];
        
        for (auto it = m.begin(); it != m.end(); ++it) {
            int d = it->first;
            // cout << d << ": " << endl; 
            // for (const auto& end_day_it : it->second) 
            //     cout << "    {" << end_day_it.first << ", " << end_day_it.second << "}" << endl;
            auto next_it = it; 
            ++next_it;
            
            int target_day = next_it == m.end() ? INT_MAX : next_it->first;
            while (!it->second.empty() && d < target_day) {
                auto end_day_it = it->second.lower_bound(d);
                if (end_day_it == it->second.end()) break;
                --end_day_it->second;
                if (end_day_it->second == 0) it->second.erase(end_day_it);
                ++d;
                ++ans;
            }
            
            if (next_it != m.end()) {                
                for (const auto& end_day_it : it->second) {
                    next_it->second[end_day_it.first] += end_day_it.second;
                }
            }
        }
        
        return ans;
    }
};