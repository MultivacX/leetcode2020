// 594. Longest Harmonious Subsequence

// Runtime: 120 ms, faster than 30.32% of C++ online submissions for Longest Harmonious Subsequence.
// Memory Usage: 21.4 MB, less than 33.33% of C++ online submissions for Longest Harmonious Subsequence.

class Solution {
public:
    int findLHS(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return 0;
        
        unordered_map<int, tuple<int, int, int>> m; // {val, {val_cnt, +1 cnt, -1 cnt}}
        int ans = 0;
        for (int num : nums) {
            if (m.count(num) == 0) 
                m.insert({num, {1, 0, 0}});
            else 
                ++get<0>(m[num]);
            
            if (m.count(num + 1)) 
                ++get<1>(m[num + 1]);
            
            if (m.count(num - 1)) 
                ++get<2>(m[num - 1]);
        }
        for (auto& it : m) 
            if (get<1>(it.second) + get<2>(it.second) > 0)
                ans = max(ans, get<0>(it.second) + max(get<1>(it.second), get<2>(it.second)));
        return ans;
    }
};