// 1712. Ways to Split Array Into Three Subarrays

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        const int N = nums.size();
        vector<int64_t> pres(N, nums[0]);
        for (int i = 1; i < N; ++i)
            pres[i] = pres[i - 1] + nums[i];
        
        int64_t ans = 0;
        for (int i = 0; i < N - 2 && pres[i] * 3 <= pres[N - 1]; ++i) {
            // l [0, i]
            
            // m [i+1, j]
            // pj - pi >= pi
            
            // r [j+1, N-1]
            // pN - pj >= pj - pi
            
            auto it = lower_bound(begin(pres) + i + 1, end(pres) - 1, 2 * pres[i]);
            if (it == end(pres) - 1) break;
            int min_j = it - begin(pres);
            
            int64_t half = (pres[N - 1] - pres[i]) / 2;
            it = lower_bound(begin(pres) + min_j, end(pres), half + pres[i]);
            if (it == end(pres)) break;
            int max_j = it - begin(pres);
            if (pres[N - 1] - pres[max_j] < pres[max_j] - pres[i])
                --max_j;
            
            if (max_j >= min_j)
                ans = (ans + max_j - min_j + 1) % 1000000007;
        }
        return ans;
    }
};