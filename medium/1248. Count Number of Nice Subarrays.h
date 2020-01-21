// 1248. Count Number of Nice Subarrays

// Runtime: 172 ms, faster than 94.93% of C++ online submissions for Count Number of Nice Subarrays.
// Memory Usage: 16.6 MB, less than 100.00% of C++ online submissions for Count Number of Nice Subarrays.

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        
        int l = -1;
        int lo = -1;
        
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (l == -1) l = i;
            if (nums[i] % 2 == 0) continue;
            if (lo == -1) lo = i;
            ++cnt;
            if (cnt == k) {
                // l <= lo <= ro <= r
                int ro = i;
                int r = i;
                while (r + 1 < nums.size() && nums[r + 1] % 2 == 0) ++r;
                
                int leftCount = lo - l + 1;
                int rightCount = r - ro + 1;
                ans += leftCount * rightCount;
                
                l = lo + 1;
                ++lo;
                while (lo < nums.size() && nums[lo] % 2 == 0) ++lo;
                --cnt;
            }
        }
        return ans;
    }
};