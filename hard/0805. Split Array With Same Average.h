// 805. Split Array With Same Average
// https://leetcode.com/problems/split-array-with-same-average/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Split Array With Same Average.
// Memory Usage: 8.5 MB, less than 5.06% of C++ online submissions for Split Array With Same Average.

class Solution {    
    int N;
    int sum;
    
    bool split(vector<int>& A, int sumB, int cntB, int i) {
        if (sumB * N == sum * cntB) return true;
        
        if (i >= N || cntB + 1 >= N) return false;
        
        if ((sumB + A[i]) / (cntB + 1) > sum / N) return false;
        
        if (split(A, sumB + A[i], cntB + 1, i + 1)) return true;
        
        // skip val == A[i]
        int j = i + 1;
        while (j < N && A[i] == A[j]) ++j;
        return split(A, sumB, cntB, j);
    }
    
public:
    bool splitArraySameAverage(vector<int>& A) {
        // sum = sumB + sumC
        // N = cntB + cntC
        // sumB / cntB <> sumC / cntC
        // sumB * N <> sum * cntB
        
        N = A.size();
        sum = accumulate(begin(A), end(A), 0);
        
        // sumB = sum * cntB / N
        bool isPossible = false;
        for (int cntB = 1; cntB < N - 1 && !isPossible; ++cntB)
            isPossible = sum * cntB % N == 0;
        if (!isPossible) return false;
        
        sort(begin(A), end(A));
        return split(A, A[0], 1, 1);
    }
};