// 995. Minimum Number of K Consecutive Bit Flips
// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/

// Runtime: 316 ms, faster than 5.10% of C++ online submissions for Minimum Number of K Consecutive Bit Flips.
// Memory Usage: 117.7 MB, less than 5.86% of C++ online submissions for Minimum Number of K Consecutive Bit Flips.
    
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        const int N = A.size();
        int S = accumulate(begin(A), end(A), 0);
        if (S == N) return 0;
        if (K == 1) return N - S;
        if (K == N) return S == 0 ? 1 : -1;
        
        int i = 0;
        int ans = 0;
        unordered_set<int> idx0, idx1;
        while (i < N) {
            if (idx0.size() == 0 && A[i] == 1) {
                // skip
            } else if (idx0.size() + idx1.size() < K) {
                A[i] == 0 ? idx0.insert(i) : idx1.insert(i);
                if (idx0.size() + idx1.size() == K) {
                    // flip
                    ++ans;
                    swap(idx0, idx1);
                    
                    // skip leading ones
                    int n = idx1.size();
                    if (n == K) {
                        idx1.clear();
                    } else {
                        int j = i + 1 - K;
                        while (n-- > 0 && idx1.count(j)) 
                            idx1.erase(j++);
                    }
                }
            }
            
            ++i;
        }
        return idx0.size() == 0 ? ans : -1;
    }
};