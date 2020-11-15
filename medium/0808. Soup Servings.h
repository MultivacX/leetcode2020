// 808. Soup Servings
// https://leetcode.com/problems/soup-servings/

// Runtime: 12 ms, faster than 47.27% of C++ online submissions for Soup Servings.
// Memory Usage: 10.4 MB, less than 38.18% of C++ online submissions for Soup Servings.

class Solution {
    unordered_map<int, unordered_map<int, double>> memo;
    
    double serve(int A, int B) {
        if (A <= 0) return B > 0 ? 1 : 0.5;
        else if (B <= 0) return 0;
        
        if (memo.count(A) && memo[A].count(B)) return memo[A][B];
        
        double ans = 0.25 * (
            serve(A - 4, B) + 
            serve(A - 3, B - 1) +
            serve(A - 2, B - 2) +
            serve(A - 1, B - 3)
        );
        memo[A][B] = ans;
        return memo[A][B];
    }
    
public:
    double soupServings(int N) {
        if (N >= 5000) return 1;
        int n = N / 25 + (N % 25 ? 1 : 0);
        return serve(n, n);
    }
};