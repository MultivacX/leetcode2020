// 164. Maximum Gap
// https://leetcode.com/problems/maximum-gap/

// Runtime: 8 ms, faster than 97.29% of C++ online submissions for Maximum Gap.
// Memory Usage: 9.4 MB, less than 13.42% of C++ online submissions for Maximum Gap.

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 1) return 0;
        
        int minv = *min_element(begin(nums), end(nums));
        int maxv = *max_element(begin(nums), end(nums));
        double gap = (maxv - minv) / (N + 1.0);
        vector<array<int, 2>> cages(N + 1, array<int, 2>{maxv, minv});
        cages[0][0] = minv;
        cages[0][1] = minv;
        cages[N][0] = maxv;
        cages[N][1] = maxv;
        for (int i = 0; i < N; ++i) {
            if (nums[i] == minv || nums[i] == maxv) continue;
            int j = (nums[i] - minv) / gap;
            cages[j][0] = min(cages[j][0], nums[i]);
            cages[j][1] = max(cages[j][1], nums[i]);
            // cout << nums[i] << " " << j << endl;
        }
        
        int ans = 0;
        for (int i = 1, pre_max = cages[0][1]; i <= N; ++i) {
            if (cages[i][0] > cages[i][1]) continue;
            // cout << cages[i][0] << ", " << cages[i][1] << endl;
            ans = max(ans, cages[i][0] - pre_max);
            pre_max = cages[i][1];
        }
        return ans;
    }
};