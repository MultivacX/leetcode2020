// 378. Kth Smallest Element in a Sorted Matrix

// Runtime: 60 ms, faster than 44.90% of C++ online submissions for Kth Smallest Element in a Sorted Matrix.
// Memory Usage: 13.1 MB, less than 40.91% of C++ online submissions for Kth Smallest Element in a Sorted Matrix.

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;
        for (auto& v : matrix) {
            for (auto i : v) {
                q.push(i);
                if (q.size() > k) {
                    q.pop();
                }
            }
        }
        return q.top();
    }
};