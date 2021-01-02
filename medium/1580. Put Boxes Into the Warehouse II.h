// 1580. Put Boxes Into the Warehouse II
// https://leetcode.com/problems/put-boxes-into-the-warehouse-ii/

// Runtime: 400 ms, faster than 32.39% of C++ online submissions for Put Boxes Into the Warehouse II.
// Memory Usage: 62.1 MB, less than 35.21% of C++ online submissions for Put Boxes Into the Warehouse II.
    
class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        const int m = boxes.size();
        sort(begin(boxes), end(boxes));
        
        const int n = warehouse.size();
        vector<int> w(n);
        for (int i = 0, h = INT_MAX; i < n; ++i) {
            h = min(h, warehouse[i]);
            w[i] = h;
        }
        for (int i = n - 1, h = INT_MAX; i >= 0; --i) {
            h = min(h, warehouse[i]);
            w[i] = max(h, w[i]);
        }
        sort(begin(w), end(w));
        
        int i = m - 1, j = n - 1, k = 0;
        while (i >= 0 && j >= 0) {
            if (boxes[i] > w[j]) --i;
            else --i, --j, ++k;
        }
        return k;
    }
};