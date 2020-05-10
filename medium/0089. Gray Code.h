// 89. Gray Code

// Runtime: 4 ms, faster than 59.67% of C++ online submissions for Gray Code.
// Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Gray Code.

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> codes{0};
        unordered_set<int> s{0};
        while (true) {
            int pre = codes.back();
            for (int i = 0; i < n; ++i) {
                int cur = pre ^ (1 << i);
                if (s.count(cur)) continue;
                codes.emplace_back(cur);
                s.emplace(cur);
                break;
            }
            if (pre == codes.back()) break;
        }
        return codes;
    }
};