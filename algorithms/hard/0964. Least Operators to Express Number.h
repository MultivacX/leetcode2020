// 964. Least Operators to Express Number
// https://leetcode.com/problems/least-operators-to-express-number/

// Runtime: 12 ms, faster than 50.75% of C++ online submissions for Least Operators to Express Number.
// Memory Usage: 7.9 MB, less than 50.75% of C++ online submissions for Least Operators to Express Number.
    
class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        unordered_set<int> visited;
        q.emplace(0, target);
        while (!q.empty()) {
            auto [k, t] = q.top(); 
            if (t == 0) return k - 1;
            q.pop();
            if (!visited.insert(t).second) continue;
            
            // x^n <= t < x^(n+1)
            int n = log(t) / log(x);
            
            int l = t - pow(x, n);
            // n == 0: -x/x, 1 [-] and 1 [/]
            // n > 0: +x*...*x, 1 [+] and n-1 [*]
            q.emplace(k + (n == 0 ? 2 : n), l);
            
            int64_t r = pow(x, n + 1) - t;
            if (r > INT_MAX) continue;
            // 1 [+] and n [*]
            q.emplace(k + n + 1, r);
        }
        return -1;
    }
};