// 1944. Number of Visible People in a Queue
// https://leetcode.com/problems/number-of-visible-people-in-a-queue/

// Runtime: 168 ms, faster than 59.74% of C++ online submissions for Number of Visible People in a Queue.
// Memory Usage: 83.9 MB, less than 95.10% of C++ online submissions for Number of Visible People in a Queue.
    
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        const int n = heights.size();
        vector<int> ans(n);
        stack<int> s;
        s.push(heights[n - 1]);
        for (int i = n - 2; i >= 0; --i) {
            if (s.empty()) {
                
            } else if (heights[i] < s.top()) {
                ans[i] = 1;
            } else {
                while (!s.empty() && heights[i] > s.top()) {
                    ++ans[i];
                    s.pop();
                }
                ans[i] += s.empty() ? 0 : 1;
            }
            s.push(heights[i]);
        }
        return ans;
    }
};