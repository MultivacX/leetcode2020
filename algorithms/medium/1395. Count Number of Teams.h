// 1395. Count Number of Teams

// Runtime: 12 ms, faster than 71.64% of C++ online submissions for Count Number of Teams.
// Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Count Number of Teams.

class Solution {
public:
    int numTeams(vector<int>& rating) {
        const int N = rating.size();
        
        set<int> ls{rating[0]};
        vector<vector<int>> l(N, {0, 0});
        for (int i = 1; i < N - 1; ++i) {
            auto it = ls.upper_bound(rating[i]);
            // *(it - 1) < rating[i] < *it
            // l[i][0] = distance(ls.begin(), it);
            // l[i][1] = distance(ls.end(), it);
            if (it == ls.begin()) {
                l[i][0] = 0;
                l[i][1] = ls.size();
            } else if (it == ls.end()) {
                l[i][0] = ls.size();
                l[i][1] = 0;
            } else {
                int greater = 0;
                while (it != ls.end()) {
                    ++it;
                    ++greater;
                }
                l[i][0] = ls.size() - greater;
                l[i][1] = greater;
            }
            
            ls.insert(rating[i]);
            // printf("L: %d < [%d] < %d\n", l[i][0], i, l[i][1]);
        }
        
        set<int> rs{rating[N - 1]};
        vector<vector<int>> r(N, {0, 0});
        for (int i = N - 2; i > 0; --i) {
            auto it = rs.upper_bound(rating[i]);
            // *(it - 1) < rating[i] < *it
            // r[i][0] = distance(rs.begin(), it);
            // r[i][1] = distance(rs.end(), it);
            if (it == rs.begin()) {
                r[i][0] = 0;
                r[i][1] = rs.size();
            } else if (it == rs.end()) {
                r[i][0] = rs.size();
                r[i][1] = 0;
            } else {
                int greater = 0;
                while (it != rs.end()) {
                    ++it;
                    ++greater;
                }
                r[i][0] = rs.size() - greater;
                r[i][1] = greater;
            }
            
            rs.insert(rating[i]);
            // printf("R: %d < [%d] < %d\n", r[i][0], i, r[i][1]);
        }
        
        int cnt = 0;
        for (int i = 1; i < N - 1; ++i) {
            cnt += l[i][0] * r[i][1] + l[i][1] * r[i][0];
        }
        return cnt;
    }
};