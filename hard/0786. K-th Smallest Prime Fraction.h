// 786. K-th Smallest Prime Fraction

// Runtime: 20 ms, faster than 69.23% of C++ online submissions for K-th Smallest Prime Fraction.
// Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for K-th Smallest Prime Fraction.

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        const int N = A.size();
        int p = 1;
        int q = A[N - 1];
        double lo = 1.0 / A[N - 1];
        double hi = 1;
        while (lo <= hi) {
            double mid = (hi + lo) * 0.5;
            double val = lo;
            int cnt = 0;
            for (int i = 0, j = 1; i < N - 1; ++i) {
                while (j < N && (double)A[i] / (double)A[j] > mid) ++j;
                if (j < N && (double)A[i] / (double)A[j] >= val) val = (double)A[i] / (double)A[j], p = A[i], q = A[j];
                cnt += N - j;
            }
            
            if (cnt == K) return {p, q};
            if (cnt < K) lo = mid;
            else hi = mid;
        }
        return {p, q};
    }
};

// Runtime Error
// 53 / 62 test cases passed.
// Line 14: Char 33: runtime error: signed integer overflow: 3926786048 * 3926786048 cannot be represented in type 'long' (solution.cpp)
/*class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        const int N = A.size();
        
        int64_t lp = 1;
        int64_t lq = A[N - 1];
        
        int64_t hp = 1;
        int64_t hq = 1;
        
        while (lp * hq < lq * hp) {
            int64_t mp = lp * hq + lq * hp;
            int64_t mq = 2 * lq * hq;
            int64_t m_gcd = gcd(mp, mq);
            mp /= m_gcd;
            mq /= m_gcd;
            
            // printf("%ld/%ld %ld/%ld %ld/%ld\n", lp, lq, mp, mq, hp, hq);
            
            int64_t p = lp;
            int64_t q = lq;
            
            int cnt = 0;
            for (int i = 0, j = 1; i < N - 1; ++i) {
                while (j < N && A[i] * mq > A[j] * mp) ++j;
                if (j < N && A[i] * q > A[j] * p) p = A[i], q = A[j];
                cnt += N - j;
            }
            
            if (cnt == K) return {(int)p, (int)q};
            if (cnt < K) lp = mp, lq = mq;
            else hp = mp, hq = mq;
        }
        return {(int)lp, (int)lq};
    }
};*/