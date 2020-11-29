// 360. Sort Transformed Array
// https://leetcode.com/problems/sort-transformed-array/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sort Transformed Array.
// Memory Usage: 9.5 MB, less than 94.97% of C++ online submissions for Sort Transformed Array.
    
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if (nums.empty()) return {};
        
        auto f = [=](int x){ return a*x*x + b*x + c; };
        
        const int N = nums.size();
        vector<int> ans(N);
        
        if (a == 0) {
            for (int i = 0; i < N; ++i) 
                ans[b >= 0 ? i : N - 1 - i] = f(nums[i]); 
            return ans;    
        }
        
        // x = -b/2a
        // a > 0, find min_idx
        // a < 0, find max_idx
        double x = -b / (2.0 * a);
        int idx = -1;
        if (x <= nums[0]) idx = 0;
        else if (x >= nums[N - 1]) idx = N - 1;
        else for (int i = 0; i + 1 < N; ++i) {
            if (nums[i] <= x && x <= nums[i + 1]) {
                idx = i;
                break;
            }
        }
        
        int i = idx, j = idx + 1, k = a > 0 ? 0 : N - 1;
        while (i >= 0 || j < N) {
            if (a > 0) {
                if (i >= 0 && j < N) {
                    int vi = f(nums[i]);
                    int vj = f(nums[j]);
                    if (vi < vj) ans[k++] = vi, --i;
                    else ans[k++] = vj, ++j;
                } else {
                    ans[k++] = i >= 0 ? f(nums[i--]) : f(nums[j++]);
                }
            } else {
                if (i >= 0 && j < N) {
                    int vi = f(nums[i]);
                    int vj = f(nums[j]);
                    if (vi < vj) ans[k--] = vj, ++j;
                    else ans[k--] = vi, --i;
                } else {
                    ans[k--] = i >= 0 ? f(nums[i--]) : f(nums[j++]);
                }
            }
        }
        return ans;
    }
};