// 1562. Find Latest Group of Size M
// https://leetcode.com/problems/find-latest-group-of-size-m/

// Runtime: 264 ms, faster than 86.96% of C++ online submissions for Find Latest Group of Size M.
// Memory Usage: 79.8 MB, less than 5.06% of C++ online submissions for Find Latest Group of Size M.

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        const int N = arr.size();
        vector<int> cnts(N + 2, 0);
        unordered_set<int> endPoints;
        int step = -1;
        for (int i = 0; i < N; ++i) {
            // [left, pre] cur [nxt, right]
            
            int cur = arr[i];
            int pre = cur - 1;
            int nxt = cur + 1;
            
            int left = cur;
            int right = cur;
            
            cnts[cur] = cnts[pre] + 1 + cnts[nxt];
            
            if (cnts[pre] != 0) {
                left = pre - cnts[pre] + 1;
                if (cnts[pre] == m) {
                    endPoints.erase(left);
                    endPoints.erase(pre);
                }
                cnts[left] = cnts[cur];
            }
            
            if (cnts[nxt] != 0) {
                right = nxt + cnts[nxt] - 1;
                if (cnts[nxt] == m) {
                    endPoints.erase(nxt);
                    endPoints.erase(right);
                }
                cnts[right] = cnts[cur]; 
            }

            if (cnts[cur] == m) {
                endPoints.insert(left);
                endPoints.insert(right);
            }
            if (!endPoints.empty()) step = i + 1;
            
            // cout << "Step " << i + 1 << ": ";
            // for (int j = 1; j <= N; ++j) cout << cnts[j] << " "; 
            // cout << endl;
        }
        return step;
    }
};