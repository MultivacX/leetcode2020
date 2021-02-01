// 403. Frog Jump

// Runtime: 152 ms, faster than 46.52% of C++ online submissions for Frog Jump.
// Memory Usage: 14.3 MB, less than 40.00% of C++ online submissions for Frog Jump.

class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones.size() <= 1) return true;
        if (stones[1] > 1) return false;
        
        unordered_set<int> s(begin(stones), end(stones));
        return jump(s, stones.back(), 0, 1);
    }
    
    unordered_map<int, unordered_map<int, bool>> m;
    
    bool jump(const unordered_set<int>& stones, int target, int unit, int k) {
        if (target < unit + k - 1) return false;
        if (unit + k - 1 <= target && target <= unit + k + 1) return true;
        if (m.count(unit) && m[unit].count(k)) return m[unit][k];
        
        if (k - 1 > 0 && stones.count(unit + k - 1) && jump(stones, target, unit + k - 1, k - 1))
            return true;
        
        if (k > 0 && stones.count(unit + k) && jump(stones, target, unit + k, k))
            return true;
        
        if (unit > 0 && k + 1 > 0 && stones.count(unit + k + 1) && jump(stones, target, unit + k + 1, k + 1))
            return true;
        
        m[unit][k] = false;
        return false;
    }
};