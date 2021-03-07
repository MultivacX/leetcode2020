// 857. Minimum Cost to Hire K Workers
// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/

// Runtime: 44 ms, faster than 70.49% of C++ online submissions for Minimum Cost to Hire K Workers.
// Memory Usage: 20.2 MB, less than 98.05% of C++ online submissions for Minimum Cost to Hire K Workers.
    
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<int> workers(quality.size());
        for (int i = 0; i < quality.size(); ++i)
            workers[i] = i;
        // sort by ratio
        sort(begin(workers), end(workers), [&](int a, int b) { 
            return wage[a] * quality[b] < wage[b] * quality[a];
        });
        
        priority_queue<int> q;
        int qualities = 0;
        
        double ans = INT_MAX;
        for (int i : workers) {
            q.push(quality[i]);
            qualities += quality[i];
            if (q.size() > K) {
                // remove current max quality
                qualities -= q.top();
                q.pop();
            }
            if (q.size() == K) {
                double ratio = (double)wage[i] / (double)quality[i];
                if (ratio * qualities < ans) ans = ratio * qualities;
            }
        }
        return ans;
    }
};