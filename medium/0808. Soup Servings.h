// 808. Soup Servings
// https://leetcode.com/problems/soup-servings/

class Solution {
    unordered_map<int, unordered_map<int, double>> memo;
    
    double serve(int A, int B) {
        if (A <= 0) return B > 0 ? 1 : 0.5;
        else if (B <= 0) return 0;
        
        if (memo.count(A) && memo[A].count(B)) return memo[A][B];
        
        double ans = 0.25 * (
            serve(A - 100, B) + 
            serve(A - 75, B - 25) +
            serve(A - 50, B - 50) +
            serve(A - 25, B - 75)
        );
        memo[A][B] = ans;
        return memo[A][B];
    }
    
public:
    double soupServings(int N) {
        return serve(N, N);
    }
};