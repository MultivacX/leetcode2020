// 832. Flipping an Image
// https://leetcode.com/problems/flipping-an-image/

// Runtime: 8 ms, faster than 71.27% of C++ online submissions for Flipping an Image.
// Memory Usage: 9.2 MB, less than 69.13% of C++ online submissions for Flipping an Image.
    
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        const int N = A.size();
        for (auto& row : A) {
            int i = 0, j = N - 1;
            while (i < j) {
                row[i] = row[i] == 1 ? 0 : 1;
                row[j] = row[j] == 1 ? 0 : 1;
                swap(row[i], row[j]);
                ++i, --j;
            }
            if (i == j) row[i] = row[i] == 1 ? 0 : 1;
        }
        return A;
    }
};