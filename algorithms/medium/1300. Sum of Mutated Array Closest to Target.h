// 1300. Sum of Mutated Array Closest to Target
// https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/

// Runtime: 36 ms, faster than 49.43% of C++ online submissions for Sum of Mutated Array Closest to Target.
// Memory Usage: 12.7 MB, less than 32.70% of C++ online submissions for Sum of Mutated Array Closest to Target.
    
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(begin(arr), end(arr));
        const int N = arr.size();
        // y = k*x - t
        int ans = arr[N - 1];
        int y = INT_MAX;
        int t = target;
        auto check = [&](int k, int x) {
            int d = abs(k * x - t);
            if (y > d) ans = x, y = d;
        };
        for (int i = 0; i < N; ++i) {
            int L = i == 0 ? 0 : arr[i - 1];
            int R = arr[i];
            int k = N - i;
            int x = t / k;
            if (L <= x && x <= R) check(k, x);
            if (L <= x && x + 1 <= R) check(k, x + 1);
            t -= arr[i];
        }
        return ans;
    }
};