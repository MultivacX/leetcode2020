// 552. Student Attendance Record II

// Runtime: 96 ms, faster than 44.99% of C++ online submissions for Student Attendance Record II.
// Memory Usage: 148.5 MB, less than 33.33% of C++ online submissions for Student Attendance Record II.

class Solution {
public:
    int checkRecord(int n) {
        static const int64_t M = 1000000000 + 7;
        // A <= 1
        // no LLL
        
        // n == 1 : P, L
        // n == 2 : PP, LP, PL, LL
        // ...
        // next_endWith__P = endWith__P + endWith__L + endWith_LL; // endWith_(P, L, LL).append(P)
        // next_endWith__L = endWith__P; // endWith_(P).append(L)
        // next_endWith_LL = endWith__L; // endWith_(L).append(L)
        vector<int64_t> endWith__P{1, 1, 2};
        vector<int64_t> endWith__L{0, 1, 1};
        vector<int64_t> endWith_LL{0, 0, 1};
        
        for (int i = 3; i <= n; ++i) {
            endWith__P.push_back((endWith__P[i - 1] + endWith__L[i - 1] + endWith_LL[i - 1]) % M);
            endWith__L.push_back(endWith__P[i - 1]);
            endWith_LL.push_back(endWith__L[i - 1]);
            // cout << i << ":" << endWith__P[i] << ", " << endWith__L[i] << ", " << endWith_LL[i] << endl;
        }
        
        // n records without A
        int ans = (endWith__P[n] + endWith__L[n] + endWith_LL[n]) % M;
         // k, A, n - k - 1 // k = [0, n - 1]
        // rewardable(n) + {rewardable(k) * rewardable(n - 1 - k), k = [0, n - 1]}
        for (int k = 0; k < n; ++k) {
            // cout << k << " A " << n - 1 - k << endl;
            int64_t left = (endWith__P[k] + endWith__L[k] + endWith_LL[k]) % M;
            int64_t right = (endWith__P[n - 1 - k] + endWith__L[n - 1 - k] + endWith_LL[n - 1 - k]) % M;
            ans = (ans + left * right % M) % M;;
        }
        return ans;
    }    
};