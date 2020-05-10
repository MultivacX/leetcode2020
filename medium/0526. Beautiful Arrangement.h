// 526. Beautiful Arrangement

// Runtime: 528 ms, faster than 16.82% of C++ online submissions for Beautiful Arrangement.
// Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for Beautiful Arrangement.

class Solution {
public:
    int countArrangement(int N) {
        int ans = 0;
        vector<bool> visited(N + 1, false);
        count(N, visited, 0, ans);
        return ans;
    }
    
    void count(const int N, vector<bool>& visited, int arranged_count, int& ans) {
        if (arranged_count == N) {
            ++ans;
            return;
        }
        
        for (int i = 1; i <= N; ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            ++arranged_count;
            if (arranged_count % i == 0 || i % arranged_count == 0)
                count(N, visited, arranged_count, ans);
            --arranged_count;
            visited[i] = false;
        }
    }
};