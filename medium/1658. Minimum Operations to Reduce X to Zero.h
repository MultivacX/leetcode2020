// 1658. Minimum Operations to Reduce X to Zero
// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

// Runtime: 692 ms, faster than 51.57% of C++ online submissions for Minimum Operations to Reduce X to Zero.
// Memory Usage: 151.6 MB, less than 40.09% of C++ online submissions for Minimum Operations to Reduce X to Zero.

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        const int N = nums.size();
        
        int ops = N + 1;
        
        vector<int> prefix;
        for (int i = 0, sum = 0; i < N; ++i) {
            sum += nums[i];
            if (sum > x) break;
            if (sum == x && ops > i + 1) ops = i + 1;
            prefix.push_back(sum);
        }
        
        unordered_map<int, int> suffix;
        for (int i = N - 1, sum = 0; i >= 0; --i) {
            sum += nums[i];
            if (sum > x) break;
            if (sum == x && ops > N - i) ops = N - i;
            suffix.insert({sum, N - i});
        }
        
        for (int i = 0; i < prefix.size(); ++i) {
            if (suffix.count(x - prefix[i]) == 0)
                continue;
            if (ops > i + 1 + suffix[x - prefix[i]])
                ops = i + 1 + suffix[x - prefix[i]];
        }
        
        return ops == N + 1 ? -1 : ops;
    }
};

// TLE
/*class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        const int N = nums.size();
        int ops = 0;
        unordered_map<int, int> m;
        m[0 * N + N - 1] = 0;
        while (!m.empty()) {
            ++ops;
            unordered_map<int, int> t;
            for (auto it : m) {
                int i = it.first / N;
                int j = it.first % N;
                int v = it.second;
                if (i == j) {
                    v += nums[i];
                    if (v == x) return ops;
                } else {
                    int l = v + nums[i];
                    if (l == x) return ops;
                    if (l < x) t[(i + 1) * N + j] = l;
                    
                    int r = v + nums[j];
                    if (r == x) return ops;
                    if (r < x) t[i * N + j - 1] = r;
                }
            }
            m = t;
        }
        return -1;
    }
};*/