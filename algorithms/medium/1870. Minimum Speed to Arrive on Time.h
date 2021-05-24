// 1870. Minimum Speed to Arrive on Time
// https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

// Runtime: 224 ms, faster than 100.00% of C++ online submissions for Minimum Speed to Arrive on Time.
// Memory Usage: 101.3 MB, less than 16.67% of C++ online submissions for Minimum Speed to Arrive on Time.
    
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        const int n = dist.size();
        int l = 1, r = 10000001;
        if (n - 1.0 + dist.back() / (double)r > hour)
            return -1;
        
        while (l < r) {
            int m = l + (r - l) / 2;
            
            double t = 0;
            for (int i = 0; i < n - 1; ++i)
                t += ceil(dist[i] / (double)m);
            t += dist.back() / (double)m;
            
            if (t > hour) l = m + 1;
            else r = m;
        }
        return l;
    }
};