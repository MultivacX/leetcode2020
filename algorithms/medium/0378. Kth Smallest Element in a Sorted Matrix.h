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


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0], r = matrix.back().back();
        while (l < r) {
            int m = l + (r - l) / 2;
            int i = 0;
            for (const auto& v : matrix) 
                i += upper_bound(begin(v), end(v), m) - begin(v);
            if (i >= k) r = m;
            else l = m + 1;
        }
        return l;
    }
};