// 862. Shortest Subarray with Sum at Least K

// Runtime: 180 ms, faster than 31.48% of C++ online submissions for Shortest Subarray with Sum at Least K.
// Memory Usage: 25.2 MB, less than 20.00% of C++ online submissions for Shortest Subarray with Sum at Least K.

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int len = A.size() + 1;
        
        int64_t sum = 0;
        // q.front < ... < q.back
        deque<pair<int64_t, int>> q;
        q.push_back({sum, 0});
        for (int i = 1; i <= A.size(); ++i) {
            sum += A[i - 1];
            
            while (!q.empty() && sum <= q.back().first) {
                // printf("idx:%d, cur:%d, del:%d,%d\n", i - 1, sum, q.back().first, q.back().second - 1);
                q.pop_back();
            }
            while (!q.empty() && sum >= q.front().first + K) {
                // printf("idx:%d, cur:%d, ***:%d,%d\n", i - 1, sum, q.front().first, q.front().second - 1);
                len = min(len, i - q.front().second);
                q.pop_front();
            }
            q.push_back({sum, i});
        }
        
        return len == A.size() + 1 ? -1 : len;
    }
};

// Time Limit Exceeded
// 85 / 93 test cases passed.
/* class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        if (A[0] >= K) return 1;
        
        int len = A.size() + 1;
        int i = 0;
        int sum = A[0];
        for (int j = 1; j < A.size(); ++j) {
            if (A[j] >= K) return 1;
            
            sum += A[j];
            if (sum <= A[j]) {
                i = j;
                sum = A[j];
            } else if (sum >= K) {
                int tmp = 0;
                for (int k = j; k >= i; --k) {
                    tmp += A[k];
                    if (tmp >= K) {
                        len = min(len, j - k + 1);
                        i = k;
                        sum = tmp;
                        break;
                    }
                }
            }
        }
        return len == A.size() + 1 ? -1 : len;
    }
}; */