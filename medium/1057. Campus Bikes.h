// 1057. Campus Bikes

// TLE
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        auto cmp = [&](pair<int, int>& l, pair<int, int>& r) { 
            const auto& wl = workers[l.first];
            const auto& bl = bikes[l.second];
            int dl = abs(wl[0] - bl[0]) + abs(wl[1] - bl[1]);
            const auto& wr = workers[r.first];
            const auto& br = bikes[r.second];
            int dr = abs(wr[0] - br[0]) + abs(wr[1] - br[1]);
            
            if (dl == dr) {
                if (l.first == r.first) return l.second > r.second;
                return l.first > r.first;
            }
            return dl > dr;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        
        for (int i = 0; i < workers.size(); ++i) 
            for (int j = 0; j < bikes.size(); ++j) 
                q.push({i, j});
        
        vector<int> ans(workers.size(), -1);
        vector<bool> assigned(bikes.size(), false);
        int N = workers.size();
        while (N > 0) {
            int i = q.top().first;
            int j = q.top().second;
            q.pop();
            if (ans[i] >= 0 || assigned[j]) continue;
            ans[i] = j;
            assigned[j] = true;
            --N;
        }
        return ans;
    }
};