// 1793. Maximum Score of a Good Subarray
// https://leetcode.com/problems/maximum-score-of-a-good-subarray/

// Runtime: 296 ms, faster than 100.00% of C++ online submissions for Maximum Score of a Good Subarray.
// Memory Usage: 179.1 MB, less than 100.00% of C++ online submissions for Maximum Score of a Good Subarray.
    
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        const int n = nums.size();
        if (n == 1) return nums[0];
        
        // [i, ..., x, ..., j]
        // nums[x] = min(nums[i ... j])
        // nums[i - 1] < nums[x] > nums[j + 1]
        // score[i, j] = nums[x] * (j - i + 1)
        
        vector<int> left_less(n, -1);
        deque<int> left_bound; left_bound.push_front(0);
        for (int i = 1; i < n; ++i) {
            if (nums[left_bound.front()] >= nums[i]) {
                left_less[i] = -1;
                
                left_bound.clear();
                left_bound.push_front(i);
            } else {
                while (nums[left_bound.back()] >= nums[i]) 
                    left_bound.pop_back();
                left_less[i] = left_bound.back();
                left_bound.push_back(i);
            }
        }
        
        int ans = left_less[n - 1] + 1 <= k ? nums[n - 1] * (n - left_less[n - 1] - 1) : 0;
        deque<int> right_bound; right_bound.push_front(n - 1);
        for (int i = n - 2; i >= 0; --i) {
            int right_less = n;
            if (nums[right_bound.front()] >= nums[i]) {
                right_bound.clear();
                right_bound.push_front(i);
            } else {
                while (nums[right_bound.back()] >= nums[i]) 
                    right_bound.pop_back();
                right_less = right_bound.back();
                right_bound.push_back(i);
            }
            if (left_less[i] + 1 <= k && k <= right_less - 1) {
                int score = nums[i] * (right_less - left_less[i] - 1);
                if (ans < score) ans = score;
            }
        }
        return ans;
    }
};