// 659. Split Array into Consecutive Subsequences

// Runtime: 268 ms, faster than 6.83% of C++ online submissions for Split Array into Consecutive Subsequences.
// Memory Usage: 33.5 MB, less than 20.00% of C++ online submissions for Split Array into Consecutive Subsequences.

class Solution {
public:
    using Q = priority_queue<int, vector<int>, greater<int>>;
    
    bool isPossible(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, Q> m;
        int n = 0;
        for (int i : nums) {
            auto pre = m.find(i - 1);
            auto cur = m.find(i);
            if (pre == m.end()) {
                if (cur == m.end()) {
                    Q q;
                    q.push(1);
                    m.insert({i, q});
                } else {
                    m[i].push(1);
                }
            } else {
                int cnt = 1 + pre->second.top();
                pre->second.pop();
                if (pre->second.empty()) {
                    m.erase(pre);
                }
                
                if (cur == m.end()) {
                    Q q;
                    q.push(cnt);
                    m.insert({i, q});    
                } else {
                    m[i].push(cnt);
                }
            }
        }
        
        for (auto it : m) {
            if (!it.second.empty() & it.second.top() < 3) return false;
        }
        
        return true;
    }
};