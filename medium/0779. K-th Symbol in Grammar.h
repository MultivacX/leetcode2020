// 779. K-th Symbol in Grammar

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for K-th Symbol in Grammar.
// Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for K-th Symbol in Grammar.

class Solution {
public:
    int kthGrammar(int N, int K) {
        //          root:k
        // left:2k-1      right:2k
        if (N == 1) return 0;
        if (N == 2) return K == 1 ? 0 : 1;
        int root = kthGrammar(N - 1, (K + 1) >> 1);
        if (K & 1) return root;
        return root == 1 ? 0 : 1;
    }
};