// 1187. Make Array Strictly Increasing

// TLE
// 19 / 21 test cases passed.
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(begin(arr2), end(arr2));
        // {num, operations}
        map<int, int> dp{{-1, 0}};
        for (int i = 0; i < arr1.size(); ++i) {
            int cur = arr1[i];
            map<int, int> m;
            for (auto [pre, ops] : dp) {
                auto it = upper_bound(begin(arr2), end(arr2), pre);
                while (it != end(arr2)) {
                    // pre < v
                    int v = *it;
                    if (m.count(v) == 0) m[v] = INT_MAX;
                    m[v] = min(m[v], ops + 1);
                    ++it;
                }
                if (pre < cur) {
                    if (m.count(cur) == 0) m[cur] = ops;
                    m[cur] = min(m[cur], ops);
                }
            }
            dp = m;
            if (dp.empty()) return -1;
        }
        int operations = INT_MAX; 
        for (auto it : dp) operations = min(operations, it.second);
        return operations == INT_MAX ? -1 : operations;
    }
};