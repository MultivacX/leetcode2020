// 503. Next Greater Element II

// Runtime: 84 ms, faster than 93.34% of C++ online submissions for Next Greater Element II.
// Memory Usage: 11.9 MB, less than 100.00% of C++ online submissions for Next Greater Element II.

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return {};
        
        vector<int> next_greater_idxes(n, -1);
        stack<int> s;
        for (int i = 0; i < 2 * n; ++i) {
            // j : [0, n)
            int j = i < n ? i : i - n;
            // printf("j:%d(%d), i:%d\n", j, nums[j], i);
            while (!s.empty()) {
                // k : [0, n)
                int k = s.top() < n ? s.top() : s.top() - n;
                // printf("  k:%d(%d)\n", k, nums[k]);
                
                // k's next greater idx : (k, n - 1 + k]
                if (i <= k || i > n - 1 + k) {
                    s.pop();
                    continue;
                }
                
                if (nums[k] >= nums[j]) 
                    break;
                
                next_greater_idxes[k] = i;
                s.pop();
            }
            s.push(i);
        }
        // for (int i = 0; i < n; ++i) 
        //     printf("idx:[%d] ngi:[%d], ", i, next_greater_idxes[i]);
        // printf("\n");
        auto& ans = next_greater_idxes;
        for (int i = 0; i < n; ++i) {
            if (next_greater_idxes[i] < 0)
                continue;
            int j = next_greater_idxes[i] < n ? next_greater_idxes[i] : next_greater_idxes[i] - n;
            ans[i] = nums[j];
        }
        return ans;
    }
};