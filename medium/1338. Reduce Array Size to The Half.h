// 1338. Reduce Array Size to The Half

// Runtime: 256 ms, faster than 54.62% of C++ online submissions for Reduce Array Size to The Half.
// Memory Usage: 34.3 MB, less than 100.00% of C++ online submissions for Reduce Array Size to The Half.

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        // {integer, cnt}
        unordered_map<int, int> m;
        for (int a : arr) ++m[a];
        
        // {cnt, kinds of integers}
        map<int, int> n;
        for (auto it : m) ++n[it.second];
        
        int ans = 0;
        int removed = 0;
        int target = arr.size() / 2;
        for (auto it = n.rbegin(); it != n.rend() && removed < target; ++it) {
            // removed + k * it->first >= target
            // 1 <= k <= it->second
            float r = floor((target - removed) / (float)it->first);
            int k = min(max(1, (int)r), it->second);
            ans += k;
            removed += k * it->first;
        }
        return ans;
    }
};