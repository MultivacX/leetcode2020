// 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/

// Runtime: 664 ms, faster than 5.33% of C++ online submissions for Minimum Difference Between Largest and Smallest Value in Three Moves.
// Memory Usage: 35.3 MB, less than 100.00% of C++ online submissions for Minimum Difference Between Largest and Smallest Value in Three Moves.

// Time Complexity: O(N).
// Space Complexity: O(1).

class Solution {
    int diff(vector<int>& nums) {
        const int N = nums.size();
        int ans = min( nums[N - 4] - nums[0], 
                       nums[N - 3] - nums[1]);
        ans = min(ans, nums[N - 2] - nums[2]);
        ans = min(ans, nums[N - 1] - nums[3]);
        return ans;
    }
    
public:
    int minDifference(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 4) return 0;
        if (N <= 8) {
            sort(begin(nums), end(nums));
            return diff(nums);
        }
        
        priority_queue<int, vector<int>, greater<int>> p;
        priority_queue<int> q;
        for (int i : nums) {
            p.push(i);
            while (p.size() > 4) p.pop();
            
            q.push(i);
            while (q.size() > 4) q.pop();
        }
        
        vector<int> v(8);
        int i = 4;
        while (!p.empty()) {
            v[i++] = p.top();
            p.pop();
        }
        i = 4;
        while (!q.empty()) {
            v[--i] = q.top();
            q.pop();
        }
        // for (int i : v) cout << i << " "; cout << endl;    
        return diff(v);
    }
};