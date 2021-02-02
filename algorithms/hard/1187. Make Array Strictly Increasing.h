// 1187. Make Array Strictly Increasing
// https://leetcode.com/problems/make-array-strictly-increasing/

// Runtime: 392 ms, faster than 32.43% of C++ online submissions for Make Array Strictly Increasing.
// Memory Usage: 69.7 MB, less than 18.02% of C++ online submissions for Make Array Strictly Increasing.
    
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(begin(arr2), end(arr2));
        // {num, operations}
        unordered_map<int, int> dp{{-1, 0}};
        for (int i = 0; i < arr1.size(); ++i) {
            int cur = arr1[i];
            unordered_map<int, int> m;
            for (auto [pre, ops] : dp) {
                if (pre < cur) {
                    if (m.count(cur) == 0) m[cur] = INT_MAX;
                    m[cur] = min(m[cur], ops);
                }
                
                auto it = upper_bound(begin(arr2), end(arr2), pre);
                if (it == end(arr2)) continue;
                int v = *it;
                if (m.count(v) == 0) m[v] = INT_MAX;
                m[v] = min(m[v], ops + 1);
            }
            dp = m;
            if (dp.empty()) return -1;
        }
        int operations = INT_MAX; 
        for (auto it : dp) operations = min(operations, it.second);
        return operations == INT_MAX ? -1 : operations;
    }
};

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