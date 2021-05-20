// 1860. Incremental Memory Leak
// https://leetcode.com/problems/incremental-memory-leak/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Incremental Memory Leak.
// Memory Usage: 6.1 MB, less than 33.34% of C++ online submissions for Incremental Memory Leak.
    
class Solution {
    float root(float a, float b, float c) {
        return (-b + sqrt(b * b - 4.0 * a * c)) * 0.5 / a;
    }
    
    int64_t sum(int64_t i, int64_t n, int64_t d = 2) {
        return (i + i + (n - 1) * d) * n / 2;
    }
    
public:
    vector<int> memLeak(int memory1, int memory2) {
        bool swaped = memory1 < memory2;
        if (swaped) swap(memory1, memory2);
            
        int i = 1;
        // (1 + i) * i / 2 == diff
        if (memory1 > memory2) {
            float diff = memory1 - memory2;
            i = floor(root(1, 1, -2.0 * diff));
            memory1 = memory1 - (int64_t)(1 + i) * i / 2;
            ++i;
        }
        // cout << i << ": " << memory1 << ", " << memory2 << endl;
        if (memory1 == memory2) swaped = false;
        
        // memory1 >= memory2
        // memory1 - i < memory2
        
        // 0 <= M - N <= 1
        
        // memory1 >= i   + ... + i+(M-1)*2
        // memory2 >= i+1 + ... + i+1+(N-1)*2
        
        int M = floor(root(1, i - 1, -memory1));
        while (M > 0) {
            int m1 = memory1 - sum(i, M);
            
            // M == N
            int m2 = memory2 - sum(i + 1, M);
            if (m2 >= 0) {
                if (swaped) swap(m1, m2);
                return {i + 1 + (M - 1) * 2 + 1, m1, m2};
            }
            
            // M == N + 1
            m2 = memory2 - sum(i + 1, M - 1);
            if (m2 >= 0) {
                if (swaped) swap(m1, m2);
                return {i + (M - 1) * 2 + 1, m1, m2};
            }
            
            --M;
        }
        
        if (swaped) swap(memory1, memory2);
        return {i, memory1, memory2};
    }
};