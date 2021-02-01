// 1049. Last Stone Weight II
// https://leetcode.com/problems/last-stone-weight-ii/

// Runtime: 4 ms, faster than 86.69% of C++ online submissions for Last Stone Weight II.
// Memory Usage: 8.9 MB, less than 36.75% of C++ online submissions for Last Stone Weight II.
    
class Solution {
    int last = INT_MAX;
    unordered_set<int> visited;
    
    void smash(vector<int>& stones, int sum, int cur, int next_idx) {
        last = min(last, abs(cur - (sum - cur)));
        
        if (next_idx >= stones.size() || visited.count(cur) || last < cur - (sum - cur))
            return;
        
        visited.insert(cur);
        for (int i = next_idx; i < stones.size(); ++i)
            smash(stones, sum, cur + stones[i], i + 1);
    }
    
public:
    int lastStoneWeightII(vector<int>& stones) {   
        smash(stones, accumulate(begin(stones), end(stones), 0), stones[0], 1);
        return last;
    }
};