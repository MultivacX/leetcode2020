// 1712. Ways to Split Array Into Three Subarrays
// https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/

// Runtime: 416 ms, faster than 83.33% of C++ online submissions for Ways to Split Array Into Three Subarrays.
// Memory Usage: 85.4 MB, less than 66.67% of C++ online submissions for Ways to Split Array Into Three Subarrays.
    
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        const int N = nums.size();
        vector<int> pres(N, nums[0]);
        for (int i = 1; i < N; ++i)
            pres[i] = pres[i - 1] + nums[i];
        
        int64_t ans = 0;
        for (int i = 0; i < N - 2; ++i) {
            // [0, i][i+1, j][j+1, N-1]
            // pj - pi >= pi
            // pN - pj >= pj - pi
            
            // 0. left <= mid <= right
            // 1. left + left <= left + mid
            // 2. mid * 2 <= mid + right
            // left <= mid <= (mid + right) / 2
            
            int left = pres[i];
            int mid_right = pres[N - 1] - left;
            if (mid_right < left + left) break;
            
            // mid
            // idx : [i+1, N-2]
            // sum : [i+1, j] ~ [i+1, k]
            auto b = begin(pres) + i + 1;
            auto e = end(pres) - 1;
            int j = lower_bound(b, e, left + left) - begin(pres);
            int k = upper_bound(b, e, left + mid_right / 2) - begin(pres) - 1;
            
            if (k >= j) ans += k - j + 1;
        }
        // cout << ans << endl;
        return ans % 1000000007;
    }
};