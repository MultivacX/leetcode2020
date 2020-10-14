// 1591. Strange Printer II
// https://leetcode.com/problems/strange-printer-ii/

// Runtime: 112 ms, faster than 75.99% of C++ online submissions for Strange Printer II.
// Memory Usage: 15.3 MB, less than 5.32% of C++ online submissions for Strange Printer II.

class Solution {
    bool test(vector<vector<int>>& targetGrid, int k, vector<int>& rect) {
        for (int i = rect[0]; i <= rect[1]; ++i) 
            for (int j = rect[2]; j <= rect[3]; ++j) 
                if (targetGrid[i][j] != k && targetGrid[i][j] != 0) 
                    return false;
        for (int i = rect[0]; i <= rect[1]; ++i) 
            for (int j = rect[2]; j <= rect[3]; ++j) 
                targetGrid[i][j] = 0;
        return true;
    }
    
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        const int M = targetGrid.size();
        const int N = targetGrid[0].size();
        // m[k] = {minRow, maxRow, minCol, maxCol, num}
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int k = targetGrid[i][j];
                if (m.count(k) == 0) m.emplace(k, vector<int>{INT_MAX, INT_MIN, INT_MAX, INT_MIN});
                m[k][0] = min(m[k][0], i);
                m[k][1] = max(m[k][1], i);
                m[k][2] = min(m[k][2], j);
                m[k][3] = max(m[k][3], j);
            }
        }
        while (!m.empty()) {
            unordered_map<int, vector<int>> t;
            for (auto it : m) 
                if (!test(targetGrid, it.first, it.second))
                    t.insert(it);
            if (m.size() == t.size()) return false;
            swap(m, t);
        }
        return true;
    }
};

// misunderstanding
// 139 / 151 test cases passed.
// Status: Wrong Answer
class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        const int M = targetGrid.size();
        const int N = targetGrid[0].size();
        // nums[k] = {minRow, maxRow, minCol, maxCol}
        vector<vector<int>> nums(61, vector<int>{INT_MAX, INT_MIN, INT_MAX, INT_MIN});
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int k = targetGrid[i][j];
                nums[k][0] = min(nums[k][0], i);
                nums[k][1] = max(nums[k][1], i);
                nums[k][2] = min(nums[k][2], j);
                nums[k][3] = max(nums[k][3], j);
            }
        }
        for (int k = 60; k > 0; --k) {
            for (int i = nums[k][0]; i <= nums[k][1]; ++i) {
                for (int j = nums[k][2]; j <= nums[k][3]; ++j) {
                    if (targetGrid[i][j] < k) return false;
                }
            }
        }
        return true;
    }
};

// overlap at 1 coner
// 102 / 151 test cases passed.
// Status: Wrong Answer
class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        const int M = targetGrid.size();
        const int N = targetGrid[0].size();
        // nums[k] = {minRow, maxRow, minCol, maxCol, num, area}
        vector<vector<int>> nums(61, vector<int>{INT_MAX, INT_MIN, INT_MAX, INT_MIN, -1, 0});
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int k = targetGrid[i][j];
                nums[k][0] = min(nums[k][0], i);
                nums[k][1] = max(nums[k][1], i);
                nums[k][2] = min(nums[k][2], j);
                nums[k][3] = max(nums[k][3], j);
                nums[k][4] = k;
            }
        }
        for (auto& num : nums) if (num[0] != INT_MAX) num[5] = (num[1] - num[0] + 1) * (num[3] - num[2] + 1);
        sort(begin(nums), end(nums), [](vector<int>& a, vector<int>& b){ return a[5] < b[5]; });
        vector<vector<int>> grid(M, vector<int>(N, 0));
        for (int k = 60; k > 0 && nums[k][5] > 0; --k) {
            // for (int i = 0; i < 6; ++i) cout << nums[k][i] << " "; cout << endl;
            for (int i = nums[k][0]; i <= nums[k][1]; ++i) {
                for (int j = nums[k][2]; j <= nums[k][3]; ++j) {
                    grid[i][j] = nums[k][4];
                }
            }
        }
        for (int i = 0; i < M; ++i) { for (int j = 0; j < N; ++j) printf("%2d ", grid[i][j]); cout << endl; }
        return targetGrid == grid;
    }
};