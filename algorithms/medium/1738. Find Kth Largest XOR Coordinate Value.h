// 1738. Find Kth Largest XOR Coordinate Value
// https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/

// Runtime: 496 ms, faster than 77.78% of C++ online submissions for Find Kth Largest XOR Coordinate Value.
// Memory Usage: 118.2 MB, less than 11.11% of C++ online submissions for Find Kth Largest XOR Coordinate Value.
    
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        priority_queue<int> q;
        vector<int> a(n, 0);
        for (int i = 0; i < m; ++i) {
            vector<int> b(n, 0);
            int l = 0;
            for (int j = 0; j < n; ++j) {
                b[j] = l ^ matrix[i][j];
                if (i > 0) b[j] ^= a[j];
                l ^= matrix[i][j];
                q.push(b[j]);
                while (q.size() > m * n - k + 1) q.pop();
                // cout << b[j] << " ";
            }
            a = b;
            // cout << endl;
        }
        return q.top();
    }
};