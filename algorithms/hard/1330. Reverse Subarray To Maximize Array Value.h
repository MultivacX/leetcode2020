// 1330. Reverse Subarray To Maximize Array Value
// https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/

// Runtime: 28 ms, faster than 83.82% of C++ online submissions for Reverse Subarray To Maximize Array Value.
// Memory Usage: 19.6 MB, less than 42.65% of C++ online submissions for Reverse Subarray To Maximize Array Value.
    
class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        const int n = nums.size();
        
        int sum = 0;
        for (int i = 0; i + 1 < n; ++i)
            sum += abs(nums[i] - nums[i + 1]);
        
        auto reverse = [&](int i, int j){
            int l = i == 0 ? 0 : abs(nums[i - 1] - nums[i]);
            int r = j + 1 >= n ? 0 : abs(nums[j] - nums[j + 1]);
            int nl = i == 0 ? 0 : abs(nums[i - 1] - nums[j]);
            int nr = j + 1 >= n ? 0 : abs(nums[i] - nums[j + 1]);
            return sum - l - r + nl + nr;
        };
        
        int ans = sum; // perform 0 operations 
        for (int i = 1; i + 1 < n; ++i) {
            ans = max(ans, reverse(0, i));
            ans = max(ans, reverse(i, n - 1));
        }
        
        int maxv = INT_MIN, minv = INT_MAX;
        for (int i = 0; i + 1 < n; ++i) {
            // min(a,b)    max(a,b)
            // |-----------|
            // |###########X#########|
            //             |@@@@@@@@@X@@@@@@@@@@@@@@@|
            //                       |+++++++++++++++|
            //                       min(c,d)        max(c,d)
            int a = nums[i], b = nums[i + 1];
            int c = nums[i], d = nums[i + 1];
            maxv = max(maxv, min(c, d));
            minv = min(minv, max(a, b));
        }
        int64_t v = sum + (maxv - minv) * 2;
        if (v > ans) return v;
        return ans;
    }
};


// WA
class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        const int n = nums.size();
        int sum = 0;
        for (int i = 0; i + 1 < n; ++i) 
            sum += abs(nums[i] - nums[i + 1]);    
        
        auto reverse = [&](int i, int j){
            int l = i == 0 ? 0 : abs(nums[i - 1] - nums[i]);
            int r = j + 1 >= n ? 0 : abs(nums[j] - nums[j + 1]);
            int nl = i == 0 ? 0 : abs(nums[i - 1] - nums[j]);
            int nr = j + 1 >= n ? 0 : abs(nums[i] - nums[j + 1]);
            return sum - l - r + nl + nr;
        };
        
        int ans = INT_MIN, mini = 0, maxi = 0;
        for (int i = 1; i < n; ++i) {
            // reverse [0, i]
            ans = max(ans, reverse(0, i));
            // cout << ans << " ";
            
            // reverse [mini, i]
            ans = max(ans, reverse(mini, i));
            // cout << ans << " ";
            
            // reverse [maxi, i]
            ans = max(ans, reverse(maxi, i));
            // cout << ans << endl;
            
            if (nums[mini] == nums[i] && mini == 0) mini = i;
            if (nums[mini] > nums[i]) mini = i;
            if (nums[maxi] == nums[i] && maxi == 0) maxi = i;
            if (nums[maxi] < nums[i]) maxi = i;
        }
        
        mini = n - 1, maxi = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            // reverse [i, n-1]
            ans = max(ans, reverse(i, n - 1));
            // cout << ans << " ";
            
            // reverse [i, mini]
            ans = max(ans, reverse(i, mini));
            // cout << ans << " ";
            
            // reverse [i, maxi]
            ans = max(ans, reverse(i, maxi));
            // cout << ans << endl;
            
            if (nums[mini] == nums[i] && mini == n - 1) mini = i;
            if (nums[mini] > nums[i]) mini = i;
            if (nums[maxi] == nums[i] && maxi == n - 1) maxi = i;
            if (nums[maxi] < nums[i]) maxi = i;
        }
        
        return ans;
    }
};