// 1296. Divide Array in Sets of K Consecutive Numbers

// Runtime: 256 ms, faster than 16.88% of C++ online submissions for Divide Array in Sets of K Consecutive Numbers.
// Memory Usage: 48.5 MB, less than 100.00% of C++ online submissions for Divide Array in Sets of K Consecutive Numbers.

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (k == 1) return true;
        if (nums.size() % k != 0) return false;
        
        sort(nums.begin(), nums.end());
        unordered_map<int, priority_queue<int>> m;
        int n = 0;
        for (int i : nums) {
            auto pre = m.find(i - 1);
            auto cur = m.find(i);
            if (pre == m.end()) {
                if (cur == m.end()) {
                    priority_queue<int> q;
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
                
                if (cnt != k) {
                    if (cur == m.end()) {
                        priority_queue<int> q;
                        q.push(cnt);
                        m.insert({i, q});    
                    } else {
                        m[i].push(cnt);
                    }   
                } else {
                    n += k;
                }
            }
        }
        
        return n == nums.size();
    }
};