// 134. Gas Station

// Runtime: 4 ms, faster than 98.95% of C++ online submissions for Gas Station.
// Memory Usage: 9 MB, less than 94.12% of C++ online submissions for Gas Station.

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();
        // if (n == 1) return 0; // ERROR if gas[0] < cost[0]
        
        int i = 0;
        while (i < n) {
            int idx = i + 1;
            int tank = gas[i] - cost[i];
            while (tank >= 0) {
                int cur_idx = idx % n;
                if (cur_idx == i)
                    return i;
                tank += gas[cur_idx] - cost[cur_idx];
                
                ++idx;
            }
            i = idx;
        }
        
        return -1;
    }
};