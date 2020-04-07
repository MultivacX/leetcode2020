// 975. Odd Even Jump

// Runtime: 152 ms, faster than 40.92% of C++ online submissions for Odd Even Jump.
// Memory Usage: 16.2 MB, less than 100.00% of C++ online submissions for Odd Even Jump.

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        const int N = A.size();
        if (N == 1) return true;
        
        // odd -> 1, even -> 2
        vector<int> can_reach(N, 0);
        // 1 | 2
        can_reach[N - 1] = 3;
        
        // {val, j}, j > i
        map<int, int> m;
        m.insert({A[N - 1], N - 1});
        
        for (int i = N - 2; i >= 0; --i) {
            int val = A[i];
            auto it = m.find(val);
            if (it == m.end()) {
                // odd
                // A[i] < A[j]
                it = m.insert({val, i}).first;
                if (++it != m.end()) {
                    int j = it->second;
                    if (can_reach[j] & 2) can_reach[i] |= 1;
                }
                
                // even
                // A[i] > A[j]
                it = m.find(val);
                if (it-- != m.begin()) {
                    int j = it->second;
                    if (can_reach[j] & 1) can_reach[i] |= 2;
                }
            } else {
                // A[i] == A[j]
                int j = it->second;
                it->second = i;
                
                // odd
                if (can_reach[j] & 2) can_reach[i] |= 1;
                // even
                if (can_reach[j] & 1) can_reach[i] |= 2;
            }
        }
        
        // for (int j = 0; j < N; ++j) printf("[%d]=%d, ", j, can_reach[j]);
        int ans = 0;
        for (int j = 0; j < N; ++j) if (can_reach[j] & 1) ++ans;
        return ans;
    }
};