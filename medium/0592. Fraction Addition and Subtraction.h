// 592. Fraction Addition and Subtraction

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fraction Addition and Subtraction.
// Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Fraction Addition and Subtraction.

class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0;
        int denominator = 1;
        const int N = expression.length();
        int i = 0;
        while (i < N) {
            bool positive = true;
            if (expression[i] == '+') ++i;
            else if (expression[i] == '-') positive = false, ++i;
            
            int n = 0;
            while (expression[i] != '/') n = n * 10 + (expression[i++] - '0');
            if (!positive) n *= -1;
            ++i;
            
            int d = 0;
            while (isdigit(expression[i])) d = d * 10 + (expression[i++] - '0');
            
            int l = lcm(denominator, d);
            numerator = numerator * l / denominator + n * l / d;
            if (numerator == 0) {
                denominator = 1;
            } else {
                denominator = l;
                int g = gcd(numerator, denominator);
                numerator /= g;
                denominator /= g;
            }
        }
        return to_string(numerator) + "/" + to_string(denominator);
    }
};