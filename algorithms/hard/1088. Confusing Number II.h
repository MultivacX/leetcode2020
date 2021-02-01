// 1088. Confusing Number II
// https://leetcode.com/problems/confusing-number-ii/

// Runtime: 1148 ms, faster than 15.42% of C++ online submissions for Confusing Number II.
// Memory Usage: 6.1 MB, less than 91.73% of C++ online submissions for Confusing Number II.
    
class Solution {
    unordered_map<int, int> m{
        {0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}
    };
    
    bool isConfusing(int64_t num) {
        int64_t cur = num;
        int64_t dst = 0;
        while (num) {
            dst = dst * 10 + m[num % 10];
            num /= 10;
        }
        return cur != dst;
    }
    
    void dfs(int64_t N, int64_t num, int& cnt) {
        if (isConfusing(num)) ++cnt;
        
        for (auto it : m) {
            int64_t nxt = num * 10 + it.first;
            if (nxt == 0 || nxt > N) continue;
            // cout << nxt << " ";
            dfs(N, nxt, cnt);
        }
    }
    
public:
    int confusingNumberII(int N) {
        int cnt = 0;
        dfs(N, 0, cnt);
        return cnt;
    }
};