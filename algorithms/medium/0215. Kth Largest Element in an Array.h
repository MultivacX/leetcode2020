// 215. Kth Largest Element in an Array

// Runtime: 12 ms, faster than 79.65% of C++ online submissions for Kth Largest Element in an Array.
// Memory Usage: 9.5 MB, less than 39.39% of C++ online submissions for Kth Largest Element in an Array.

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k + 1;
        priority_queue<int> q;
        for (int i : nums) {
            q.push(i);
            if (q.size() > k) q.pop();
        }
        return q.top();
    }
};