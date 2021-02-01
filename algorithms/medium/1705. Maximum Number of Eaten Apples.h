// 1705. Maximum Number of Eaten Apples
// https://leetcode.com/problems/maximum-number-of-eaten-apples/

// Runtime: 252 ms, faster than 88.04% of C++ online submissions for Maximum Number of Eaten Apples.
// Memory Usage: 57.4 MB, less than 14.31% of C++ online submissions for Maximum Number of Eaten Apples.
    
class Solution {    
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        // v apples will be rotten at day-k
        map<int, int> m;
        const int N = apples.size();
        int ans = 0;
        int day = 1;
        while (day <= N || !m.empty()) {
            if (day <= N) m[day - 1 + days[day - 1]] += apples[day - 1];
            while (!m.empty() && m.begin()->first < day)
                m.erase(m.begin());
            if (!m.empty() && m.begin()->first >= day) {
                ++ans;
                if (--m.begin()->second == 0)
                    m.erase(m.begin());
            }
            ++day;
        }
        return ans;
    }
};