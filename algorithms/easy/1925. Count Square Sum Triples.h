// 1925. Count Square Sum Triples
// https://leetcode.com/problems/count-square-sum-triples/

// Runtime: 4 ms, faster than 97.93% of C++ online submissions for Count Square Sum Triples.
// Memory Usage: 5.9 MB, less than 77.90% of C++ online submissions for Count Square Sum Triples.
    
class Solution {
public:
    int countTriples(int n) {
        int k = 0;
        for (int a = 1; a <= n; ++a) {
            for (int b = a; b <= n; ++b) {
                int C = a * a + b * b;
                int c = sqrt(C);
                if (c > n) break;
                if (c * c != C) continue;
                ++k;
            }
        }
        return k * 2;
    }
};