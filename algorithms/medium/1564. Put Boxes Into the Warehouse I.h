// 1564. Put Boxes Into the Warehouse I
// https://leetcode.com/problems/put-boxes-into-the-warehouse-i/

// Runtime: 304 ms, faster than 73.64% of C++ online submissions for Put Boxes Into the Warehouse I.
// Memory Usage: 60.9 MB, less than 49.09% of C++ online submissions for Put Boxes Into the Warehouse I.
    
class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        const int M = warehouse.size();
        const int N = boxes.size();
        int ans = 0;
        
        for (int i = 0, minv = warehouse[0]; i < M; ++i) 
            if (warehouse[i] >= minv) warehouse[i] = minv;
            else minv = warehouse[i];
        
        sort(begin(boxes), end(boxes));
        for (int i = 0, j = -1; i < N; ++i) {
            if (j == -1) {
                while (j + 1 < M && warehouse[j + 1] >= boxes[i])
                    ++j;
            }
            while (j >= 0 && warehouse[j] < boxes[i]) --j;
            bool found = j >= 0;
            if (found) --j, ++ans;
            if (!found || j < 0) break;
        }
        return ans;
    }
};