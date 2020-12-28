// 922. Sort Array By Parity II
// https://leetcode.com/problems/sort-array-by-parity-ii/

// Runtime: 36 ms, faster than 87.04% of C++ online submissions for Sort Array By Parity II.
// Memory Usage: 21.8 MB, less than 84.87% of C++ online submissions for Sort Array By Parity II.
    
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        const int N = A.size();
        vector<int> B(N);
        int i = 0, j = 1;
        for (int a : A) {
            if (a % 2 == 0) B[i] = a, i += 2;
            else B[j] = a, j += 2;
        }
        return B;
    }
};