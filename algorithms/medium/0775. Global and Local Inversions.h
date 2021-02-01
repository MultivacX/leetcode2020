// 775. Global and Local Inversions

// Runtime: 416 ms, faster than 5.16% of C++ online submissions for Global and Local Inversions.
// Memory Usage: 71.3 MB, less than 14.29% of C++ online submissions for Global and Local Inversions.

// Time Complexity: O(N * lg(N)).
// Space Complexity: O(1).

class Solution {
    int global = 0;
    
    void sort(vector<int>& A, int begin, int end) {
        if (begin + 1 >= end) return;
        
        int mid = begin + (end - begin) / 2;
        sort(A, begin, mid);
        sort(A, mid, end);
        
        for (int i = begin, j = mid; j < end; ++j) {
            if (i == begin) {
                auto it = upper_bound(A.begin() + begin, A.begin() + mid, A[j]);
                if (it == A.begin() + mid) break;
                i = it - A.begin();
            }
            while (i < mid && A[i] <= A[j]) ++i;
            if (i >= mid) break;
            global += mid - i;
        }
        
        inplace_merge(A.begin() + begin, A.begin() + mid, A.begin() + end);
    }
    
public:
    bool isIdealPermutation(vector<int>& A) {
        const int N = A.size();
        
        int local = 0;
        for (int i = 0; i < N - 1; ++i) if (A[i] > A[i + 1]) ++local;
        
        sort(A, 0, A.size());
        
        return local == global;
    }
};