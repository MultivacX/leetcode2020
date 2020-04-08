// 719. Find K-th Smallest Pair Distance

// Time Limit Exceeded
// 12 / 19 test cases passed.
class Solution {
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
};