// 1330. Reverse Subarray To Maximize Array Value

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