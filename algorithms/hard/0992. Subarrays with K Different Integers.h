// 992. Subarrays with K Different Integers
// https://leetcode.com/problems/subarrays-with-k-different-integers/

// Runtime: 216 ms, faster than 54.94% of C++ online submissions for Subarrays with K Different Integers.
// Memory Usage: 46.3 MB, less than 37.04% of C++ online submissions for Subarrays with K Different Integers.
    
class Solution {
    struct Window {
        int left = 0;
        // {A[i], freq}
        unordered_map<int, int> freqs;
    };
    
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        // subarrays end with A[i]
        // maxw.freqs.size() == minw.freqs.size() == K
        // [maxw.left, ..., minw.left, ..., i]
        //                 [minw.left, ..., i]
        Window maxw, minw;
        int ans = 0;
        for (int i = 0; i < A.size(); ++i) {
            int a = A[i];
            if (maxw.freqs.size() < K || maxw.freqs.count(a)) {
                ++maxw.freqs[a];
                ++minw.freqs[a];
            } else {
                // Time Limit Exceeded
                // 52 / 55 test cases passed.
                /*maxw = minw; // optim?
                while (maxw.freqs.size() >= K) {
                    int b = A[maxw.left++];
                    minw.left++;
                    if (--maxw.freqs[b] == 0) {
                        maxw.freqs.erase(b);
                        minw.freqs.erase(b);
                    }
                }*/
                while (maxw.freqs.size() >= K) {
                    if (minw.left == maxw.left)
                        minw.left++;
                    int b = A[maxw.left++];
                    if (--maxw.freqs[b] == 0) {
                        maxw.freqs.erase(b);
                        if (minw.left == maxw.left)
                            minw.freqs.erase(b);
                    }
                }
                ++maxw.freqs[a];
                ++minw.freqs[a];
            }
            
            if (minw.freqs.size() >= K) {
                while (minw.freqs[A[minw.left]] > 1) 
                    --minw.freqs[A[minw.left++]];
                ans += minw.left - maxw.left + 1;
            }
        }
        return ans;
    }
};