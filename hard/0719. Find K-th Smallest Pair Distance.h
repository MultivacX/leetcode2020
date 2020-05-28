// 719. Find K-th Smallest Pair Distance

// Runtime: 88 ms, faster than 16.75% of C++ online submissions for Find K-th Smallest Pair Distance.
// Memory Usage: 10.2 MB, less than 8.33% of C++ online submissions for Find K-th Smallest Pair Distance.

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        const int N = nums.size();
        sort(begin(nums), end(nums));
        int lo = 0;
        int hi = nums[N - 1] - nums[0];
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            int cnt = 0;
            int val = 0;
            for (int i = 0; i < N - 1; ++i) {
                auto it = upper_bound(begin(nums) + i + 1, end(nums), nums[i] + mid);
                int j = it - begin(nums) - 1;
                val = max(val, nums[j] - nums[i]);
                cnt += j - i;
            }
            
            if (cnt == k) return val;
            if (cnt < k) lo = mid + 1;
            else hi = mid - 1;
        }
        return lo;
    }
};

// Time Limit Exceeded
// 18 / 19 test cases passed.
/*class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        const int N = nums.size();
        sort(begin(nums), end(nums));
        int lo = 0;
        int hi = nums[N - 1] - nums[0];
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            int cnt = 0;
            int val = 0;
            for (int i = 0; i < N; ++i) 
                for (int j = i - 1; j >= 0 && nums[i] - nums[j] <= mid; --j) 
                    ++cnt, val = max(val, nums[i] - nums[j]);
            
            if (cnt == k) return val;
            if (cnt < k) lo = mid + 1;
            else hi = mid - 1;
        }
        return lo;
    }
};*/

// Time Limit Exceeded
// 12 / 19 test cases passed.
/*class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        const int N = nums.size();
        int min_val = nums[0];
        int max_val = nums[0];
        for (int i = 1; i < N; ++i) {
            min_val = min(min_val, nums[i]);
            max_val = max(max_val, nums[i]);
        }
        int max_distance = max_val - min_val;
        if (max_distance == 0 || k == N * (N - 1) / 2) return max_distance;
        
        unordered_map<int, int> m;
        for (int i : nums) ++m[i];
        
        for (int dist = 0; dist <= max_distance; ++dist) {
            for (const auto& p : m) {
                if (dist == 0) {
                    k -= p.second * (p.second - 1) / 2;
                } else if (m.count(p.first - dist)) {
                    k -= p.second * m[p.first - dist];
                }
                if (k <= 0) return dist;
            }    
        }
        return max_distance;
    }
};*/