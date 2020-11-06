// 805. Split Array With Same Average
// https://leetcode.com/problems/split-array-with-same-average/

class Solution {
    unordered_map<int, bool> memo;
    // sum, len
        
    bool split(vector<int>& A, int sumA, int sumB, int cntB, int i, int used) {
        const int cntA = A.size();
        // cout << sumB << "/" << cntB << "=" << sumB/(double)cntB << endl;
        bool found = cntB != cntA && sumB * cntA == sumA * cntB;
        if (i >= cntA) return found;
        if (found) return true;
        if (memo.count(used)) return memo[used];
        
        memo[used] = split(A, sumA, sumB + A[i], cntB + 1, i + 1, used | (1 << (i - 1))) || 
                     split(A, sumA, sumB,        cntB,     i + 1, used);
        return memo[used];
    }
    
public:
    bool splitArraySameAverage(vector<int>& A) {
        // sumA = sumB + sumC
        // cntA = cntB + cntC
        //   
        //   sumB        / cntB       <> sumC        / cntC
        //   (sumB + Ai) / (cntB + 1) <> (sumC - Ai) / (cntC - 1)
        //   (sumB + Ai) * (cntC - 1) <> (sumC - Ai) * (cntB + 1)
        //   
        //   sumB        * cntA <> sumA * cntB
        //   (sumB + Ai) * cntA <> sumA * (cntB + 1)
        
        return split(A, accumulate(begin(A), end(A), 0), A[0], 1, 1, 1);
    }
};