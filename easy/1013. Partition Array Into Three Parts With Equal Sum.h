// 1013. Partition Array Into Three Parts With Equal Sum
// https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/submissions/

// Runtime: 84 ms, faster than 93.53% of C++ online submissions for Partition Array Into Three Parts With Equal Sum.
// Memory Usage: 32.2 MB, less than 6.08% of C++ online submissions for Partition Array Into Three Parts With Equal Sum.

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(begin(A), end(A), 0);
        if (sum % 3) return false;
        sum /= 3;
        
        const int N = A.size();
        
        int i = 0;
        int s = A[0];
        while (i + 1 < N - 2 && s != sum) s += A[++i];
        if (i >= N - 2) return false;
        
        int j = N - 1;
        s = A[N - 1];
        while (j - 1 > i && s != sum) s += A[--j];
        if (i + 1 >= j) return false;
        
        return true;
    }
};