// 640. Solve the Equation

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Solve the Equation.
// Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for Solve the Equation.

class Solution {
public:
    string solveEquation(string equation) {
        const int N = equation.length();
        
        int n = 0;
        int x = 0;
        int i = 0;
        
        while (i < N && equation[i] != '=') {
            bool positive = true;
            if (equation[i] == '+') ++i;
            else if (equation[i] == '-') positive = false, ++i;
            
            int v = 0;
            if (equation[i] == 'x') v = 1;
            else while (i < N && isdigit(equation[i])) v = v * 10 + (equation[i++] - '0');
            if (!positive) v *= -1;
            if (i < N && equation[i] == 'x') x += v, ++i;
            else n += v;
            
            // printf("%d, x * %d + %d\n", v, x, n);
        }
        
        ++i;
        
        while (i < N) {
            bool positive = false;
            if (equation[i] == '+') ++i;
            else if (equation[i] == '-') positive = true, ++i;
            
            int v = 0;
            if (equation[i] == 'x') v = 1;
            else while (i < N && isdigit(equation[i])) v = v * 10 + (equation[i++] - '0');
            if (!positive) v *= -1;
            if (i < N && equation[i] == 'x') x += v, ++i;
            else n += v;
            
            // printf("x * %d + %d\n", x, n);
        }
        
        if (x == 0) return n == 0 ? "Infinite solutions" : "No solution";
        return "x=" + to_string(-n / x);
    }
};