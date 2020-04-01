// 918. Maximum Sum Circular Subarray

// Runtime: 212 ms, faster than 5.21% of C++ online submissions for Maximum Sum Circular Subarray.
// Memory Usage: 18.2 MB, less than 16.67% of C++ online submissions for Maximum Sum Circular Subarray.

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        const int N = A.size();
        int max_sum = A[0];
        vector<int> sums(2 * N - 1, A[0]);
        deque<pair<int, int>> L{{A[0], 0}};
        for (int i = 1; i < 2 * N - 1; ++i) {
            sums[i] = sums[i - 1] + A[i % N];
            max_sum = max(max_sum, i < N ? sums[i] : sums[i] - sums[i - N]);
            while (!L.empty() && (L.back().first >= sums[i] || i - L.back().second >= N)) {
                if (i - L.back().second < N) 
                    max_sum = max(max_sum, sums[i] - L.back().first);
                L.pop_back();
            }
            while (!L.empty() && i - L.front().second >= N) 
                L.pop_front();
            if (!L.empty()) 
                max_sum = max(max_sum, sums[i] - L.front().first);
            L.push_back({sums[i], i});
        }
        return max_sum;
    }
};

// Runtime: 360 ms, faster than 5.21% of C++ online submissions for Maximum Sum Circular Subarray.
// Memory Usage: 52.9 MB, less than 8.33% of C++ online submissions for Maximum Sum Circular Subarray.

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        const int N = A.size();
        int max_sum = A[0];
        vector<int> sums(2 * N - 1, A[0]);
        list<pair<int, int>> L{{A[0], 0}};
        for (int i = 1; i < 2 * N - 1; ++i) {
            sums[i] = sums[i - 1] + A[i % N];
            max_sum = max(max_sum, i < N ? sums[i] : sums[i] - sums[i - N]);
            while (!L.empty() && (L.back().first >= sums[i] || i - L.back().second >= N)) {
                if (i - L.back().second < N) 
                    max_sum = max(max_sum, sums[i] - L.back().first);
                L.pop_back();
            }
            while (!L.empty() && i - L.front().second >= N) 
                L.pop_front();
            if (!L.empty()) 
                max_sum = max(max_sum, sums[i] - L.front().first);
            L.push_back({sums[i], i});
        }
        return max_sum;
    }
};