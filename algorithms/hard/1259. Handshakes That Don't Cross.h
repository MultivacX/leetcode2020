// 1259. Handshakes That Don't Cross
// https://leetcode.com/problems/handshakes-that-dont-cross/

// Runtime: 4 ms, faster than 97.78% of C++ online submissions for Handshakes That Don't Cross.
// Memory Usage: 6.2 MB, less than 80.00% of C++ online submissions for Handshakes That Don't Cross.
    
class Solution {
public:
    int numberOfWays(int num_people) {
        static const int64_t n = 1000000007;
        static vector<int64_t> ways{1, 1, 2, 5, 14};
        
        const int idx = num_people / 2;
        if (idx < ways.size() && ways[idx] > 0)
            return ways[idx];
        
        int64_t ans = 0;
        for (int i = 1; i < num_people; i += 2) {
            ans = (ans + (int64_t)numberOfWays(i - 1) * (int64_t)numberOfWays(num_people - i - 1) % n) % n;
        }
        if (idx >= ways.size())
            ways.resize(idx + 1);
        ways[idx] = ans;
        return ans;
    }
};