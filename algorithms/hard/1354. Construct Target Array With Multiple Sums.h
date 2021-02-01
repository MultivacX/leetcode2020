// 1354. Construct Target Array With Multiple Sums
// https://leetcode.com/problems/construct-target-array-with-multiple-sums/

// Runtime: 96 ms, faster than 73.97% of C++ online submissions for Construct Target Array With Multiple Sums.
// Memory Usage: 30.2 MB, less than 5.02% of C++ online submissions for Construct Target Array With Multiple Sums.

class Solution {
public:
    bool isPossible(vector<int>& target) {
        const int N = target.size();
        if (N == 1) return target[0] == 1;
        int64_t sum = accumulate(begin(target), end(target), (int64_t)0);
        if ((int64_t)N == sum) return true;
        priority_queue<int> q;
        for (int t : target) q.push(t);
        while (true) {
            if (q.top() == 1) return true;

            // T : present
            // sum          = (target[x] + ... + target[y]) + target[i][T]
            // target[i][T] = (target[x] + ... + target[y]) + target[i][T - 1]
            
            // sum = delta + maxv
            //     = delta + (k * delta + prev)
            // k >= 0

            int maxv = q.top();
            int delta = sum - maxv;
            if (delta < N - 1) return false;
            if (delta == N - 1) return (maxv - 1) % (N - 1) == 0;
            
            int k = maxv / delta;
            if (k < 1) return false;
            
            int prev = maxv - k * delta;
            if (prev < 1) return false;
            
            sum = delta + prev;
            q.pop();
            q.push(prev);
        }
        return false;
    }
};